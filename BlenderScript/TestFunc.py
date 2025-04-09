import bpy
import mathutils
import json
import math
import numpy as np # type: ignore

def Get_LocalRotation(armature_name, bone_name, startRotationMatrix):
    """
    计算骨骼相对于初始旋转的局部旋转矩阵。

    参数：
    - armature_name (str): 目标骨架对象名称
    - bone_name (str): 目标骨骼名称
    - startRotationMatrix (mathutils.Matrix): 初始的旋转矩阵（4x4）

    返回：
    - mathutils.Matrix: 骨骼相对于初始姿态的局部旋转矩阵
    """
    # 获取骨架对象
    armature = bpy.data.objects.get(armature_name)
    if not armature:
        raise ValueError(f"错误：未找到骨架 '{armature_name}'")

    # 获取骨骼
    bone = armature.pose.bones.get(bone_name)
    if not bone:
        raise ValueError(f"错误：骨骼 '{bone_name}' 不存在")

    # 获取当前骨骼的世界旋转矩阵
    world_rotation_boneNow = armature.matrix_world @ bone.matrix

    # 获取当前父骨骼的世界旋转矩阵
    world_rotation_boneParentNow = armature.matrix_world @ bone.parent.matrix

    # 计算骨骼在初始状态下的世界旋转矩阵
    world_rotation_boneStart = world_rotation_boneParentNow @ startRotationMatrix

    # 计算局部旋转矩阵
    local_rotation_matrix = world_rotation_boneStart.inverted() @ world_rotation_boneNow

    return local_rotation_matrix


def get_deform_bones(armature_name):
    """
    获取指定骨架下的所有形变骨（Deform Bones）。

    参数：
    - armature_name (str): 目标骨架名称

    返回：
    - list[str]: 形变骨名称列表
    """
    armature = bpy.data.objects.get(armature_name)
    if not armature or armature.type != 'ARMATURE':
        print(f"错误：未找到骨架 '{armature_name}'")
        return []

    return [bone.name for bone in armature.data.bones if bone.use_deform]


def save_bone_initial_rotation_to_json(armature_name, output_path):
    """
    计算所有形变骨的初始旋转（旋转矩阵），并存储为 JSON 文件。

    参数：
    - armature_name (str): 目标骨架名称
    - output_path (str): 输出 JSON 文件的路径
    """
    allDeformBones = get_deform_bones(armature_name)
    bone_rotation_data = {}

    for bone_name in allDeformBones:
        # 这里传入的是单位矩阵（即无旋转）
        boneInitialRotate = Get_LocalRotation(armature_name, bone_name, mathutils.Matrix.Identity(4))

        # 存储旋转矩阵（转换为列表）
        bone_rotation_data[f"{bone_name}_InitialRotate"] = [
            list(row) for row in boneInitialRotate
        ]

    with open(output_path, "w", encoding="utf-8") as json_file:
        json.dump(bone_rotation_data, json_file, indent=4)

    print(f"骨骼初始旋转数据已保存到 {output_path}")


def load_rotation_from_json(armature_name, bone_name, json_path):
    """
    从 JSON 文件中读取目标骨骼的旋转矩阵，并计算 LocalRotation（旋转矩阵）。

    参数：
    - armature_name (str): 目标骨架名称
    - bone_name (str): 目标骨骼名称
    - json_path (str): JSON 文件的路径

    返回：
    - mathutils.Matrix: 计算出的局部旋转矩阵 (4x4)
    """
    with open(json_path, "r", encoding="utf-8") as json_file:
        bone_rotation_data = json.load(json_file)

    bone_key = f"{bone_name}_InitialRotate"

    if bone_key not in bone_rotation_data:
        raise ValueError(f"错误: JSON 文件中找不到骨骼 '{bone_name}' 的旋转数据")

    # 解析存储的旋转矩阵
    start_rotation_matrix = mathutils.Matrix(bone_rotation_data[bone_key])

    # 计算局部旋转矩阵
    local_rotation_matrix = Get_LocalRotation(armature_name, bone_name, start_rotation_matrix)

    return local_rotation_matrix

def matrix_to_zyx_euler(matrix):
    """
    将旋转矩阵转换为 ZYX 欧拉角（角度制）。

    参数：
    - matrix (mathutils.Matrix): 旋转矩阵 (4x4 或 3x3)

    返回：
    - tuple (float, float, float): (Z, Y, X) 欧拉角（角度制）
    """
    if not isinstance(matrix, mathutils.Matrix):
        raise TypeError("输入必须是 mathutils.Matrix 类型")

    # 确保是 3x3 矩阵（去掉平移部分）
    rotation_matrix = matrix.to_3x3()

    # 转换为欧拉角（ZYX 顺序）
    euler = rotation_matrix.to_euler('ZYX')

    # 转换为角度制，并减少浮点误差
    return (
        round(math.degrees(euler.z), 6),
        round(math.degrees(euler.y), 6),
        round(math.degrees(euler.x), 6)
    )


def update_mass_point():
    """
    计算场景中所有带有 'weight' 自定义属性的物体的加权重心，并将 'MassPoint' 物体移动到该位置。
    """
    mass_point = bpy.data.objects.get("MassPoint")

    if not mass_point:
        print("未找到名为 'MassPoint' 的物体。")
        return

    total_weight = 0.0
    weighted_sum = np.array([0.0, 0.0, 0.0])

    # 遍历所有物体，计算加权重心
    for obj in bpy.data.objects:
        if "weight" in obj.keys():  # 确保物体有 weight 属性
            weight = obj["weight"]
            pos = np.array(obj.matrix_world.translation)

            total_weight += weight
            weighted_sum += weight * pos

    # 计算加权重心
    if total_weight > 0:
        center_of_mass = weighted_sum / total_weight
        mass_point.location = mathutils.Vector(center_of_mass)
        print(f"MassPoint 已移动至 {center_of_mass}")
    else:
        print("没有找到带有 'weight' 属性的物体，无法计算重心。")

def get_posebone_property(armature_name, bone_name, prop_name):
    """
    获取、设置或列出姿态骨的自定义属性。
    :param armature_name: 骨架对象名称
    :param bone_name: 骨骼名称
    :param prop_name: 自定义属性名称
    :param value: 如果提供，则设置属性值；否则获取属性值
    :return: 属性值（如果获取），或属性字典（如果 prop_name 为空），或操作成功与否（如果设置）
    """
    value=None
    armature = bpy.data.objects.get(armature_name)
    if not armature or armature.type != 'ARMATURE':
        raise ValueError(f"对象 '{armature_name}' 不是一个有效的骨架对象")
    
    bone = armature.pose.bones.get(bone_name)
    if not bone:
        raise ValueError(f"骨骼 '{bone_name}' 在 '{armature_name}' 中不存在")
    
    if value is not None:
        # 设置自定义属性
        bone[prop_name] = value
        return True
    elif prop_name:
        # 获取自定义属性
        return bone.get(prop_name, None)
    else:
        # 列出所有自定义属性
        return {key: val for key, val in bone.items()}

def get_servo_prop(json_path, target_id, prop):
    try:
        with open(json_path, 'r', encoding='utf-8') as file:
            data = json.load(file)
        
        for servo in data.get("servos", []):
            if servo.get("ID") == target_id:
                return servo.get(prop)
        
        return None  # 若未找到对应ID，返回None
    except (FileNotFoundError, json.JSONDecodeError) as e:
        print(f"Error: {e}")
        return None
