import bpy
import mathutils
import math
import sys
import os
import time
import threading
import select
import json

sys.path.append(os.path.abspath("/Users/dongzhuyu/Coding/Python/MyRobot/"))
import TestFunc as TF
import UDPSend

armature_name = "骨架"
bone_json_path = "./BonesInitial.json"
servo_json_path = "./ServoInitial.json"


allDeformBones = TF.get_deform_bones(armature_name)

def main():
    while 1:
        for deformBone in allDeformBones:
            ID = int(TF.get_posebone_property(armature_name,deformBone,"ID"))
            Rotate_Angle = int(TF.matrix_to_zyx_euler(TF.load_rotation_from_json(armature_name, deformBone, bone_json_path))[0])
            if(TF.get_servo_prop(servo_json_path,ID,"isChanging") == 0):
                Rotate_Angle = Rotate_Angle + TF.get_servo_prop(servo_json_path,ID,"degree")
            elif(TF.get_servo_prop(servo_json_path,ID,"isChanging") == 1):
                Rotate_Angle = -Rotate_Angle + TF.get_servo_prop(servo_json_path,ID,"degree")
            UDPSend.SetServoAngle(ID,int(Rotate_Angle))
            
            time.sleep(0.001)
            
        TF.update_mass_point()
        

# 启动主线程
thread = threading.Thread(target=main)
thread.start()

