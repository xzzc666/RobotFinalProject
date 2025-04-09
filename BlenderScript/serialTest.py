import serial
import serial.tools.list_ports
from serial import SerialException

def list_ports():
    """ 列出可用的串口设备 """
    ports = serial.tools.list_ports.comports()
    return [port.device for port in ports]

def monitor_serial(port, baudrate=115200, timeout=1):
    """ 以十六进制格式监控串口数据 """
    try:
        with serial.Serial(port, baudrate, timeout=timeout) as ser:
            print(f"Monitoring {port} at {baudrate} baud (Press Ctrl+C to exit)...")
            while True:
                try:
                    if ser.in_waiting > 0:  # 确保有数据再读取
                        data = ser.read(ser.in_waiting)  # 读取所有可用数据
                        hex_data = " ".join(f"{b:02X}" for b in data)  # 转换为 16 进制
                        print(f"Received ({len(data)} bytes): {hex_data}")
                except SerialException as e:
                    print(f"Serial error: {e}")
                    break
                except ValueError as e:
                    print(f"Value error: {e}")
                    break
    except (SerialException, ValueError) as e:
        print(f"Error opening port: {e}")
    except KeyboardInterrupt:
        print("\nMonitoring stopped.")

if __name__ == "__main__":
    available_ports = list_ports()
    if not available_ports:
        print("No serial ports found.")
    else:
        print("Available ports:", available_ports)
        selected_port = input("Enter port name (e.g., COM3 or /dev/ttyUSB0): ").strip()
        if selected_port in available_ports:
            monitor_serial(selected_port)
        else:
            print("Invalid port selected.")
