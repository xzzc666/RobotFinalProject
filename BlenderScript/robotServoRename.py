import socket
import time

# 目标 ESP32 设备的 IP 和端口
ESP32_IP = "192.168.4.10"  # ESP32 的 IP 地址
ESP32_PORT = 514           # ESP32 监听的 UDP 端口

# 创建 UDP 套接字

def send_command(command):
    """ 发送 UDP 命令到 ESP32 """
    
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(command.encode(), (ESP32_IP, ESP32_PORT))
    
    sock.close()
    print(f"发送: {command}")
    


# 示例：发送 ID:2 ResetID:10
# 示例：发送 ID:1 Degree:90


def TestAndReset(targetID, sleepTime):
    
    send_command("ID:0 ResetID:" + str(targetID))
    time.sleep(1)
    for i in range(25):
        send_command("ID:"+str(targetID)+" Degree:" + str(i*10))
        
        time.sleep(sleepTime)
        

    send_command("ID:"+str(targetID)+" Degree:" + str(120))

    time.sleep(sleepTime)

    send_command("ID:"+str(targetID)+" Degree:" + str(120))


TestAndReset(14, 0.1)