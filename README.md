## COMPETITION KIT
<p align="center" width="100%">
    <img width="60%" src="Docs/Images/Cvpro_Com_Kit_1.png" />
</p>

The CV Pro Competition kit is crafted for the future engineers who compete in various competitions, opening the door to the realm of autonomous technology, and enabling exploration in the sphere of cutting-edge innovations.The kit empowers users with functionalities including color sensors and ultrasonic sensors for color detection and obstacle avoidance during navigation. It can effectively monitor its surroundings using these sensors and even follow a specified color path when programmed accordingly. Our CV Pro competition kit seamlessly integrates with Android mobile phones for optimal compatibility and performance.

## You can download the APK from this [link](https://drive.google.com/drive/u/0/folders/1uq9PmImZiYLncMbVU259YYULkfPL1bhg)

# 🤖 CVPro Competition Kit

## 🔧 What is the CVPro Competition Kit?

The **CVPro Competition Kit** is a 4-wheel robot DIY kit tailored for high-performance in AI and robotics competitions, especially aligned with the **WRO (World Robot Olympiad) Future Engineers** category. With modular hardware and AI-driven capabilities, this kit allows participants to build, program, and train their robot to tackle real-world tasks using vision and sensor data.

---

## 🛠️ Hardware Provided

This robust kit includes all essential components to build and operate a fully functional AI-powered robot:

1. **CVPro Controller (ESP32-based)**  
   - High-performance microcontroller with Wi-Fi and Bluetooth support for real-time AI and sensor integration.

2. **Servo Motor with Ackerman Steering System**  
   - Enables precise directional control, emulating real-world vehicle steering.

3. **DC Motor with Optical Encoder**  
   - Controls forward and backward movement with feedback on speed and distance.

4. **Color Sensor**  
   - Detects colored zones or lines on the ground.

5. **Six Ultrasonic Sensors**  
   - **Front (3)**: Obstacle detection  
   - **Rear (1)**: Reverse movement safety  
   - **Left (1) & Right (1)**: Side obstacle detection

6. **Push Button**  
   - Used to initiate robot tasks and programs.

7. **Programmable RGB LED**  
   - Visual status indication via customizable colors.

8. **Mobile Phone Holder**  
   - Holds a smartphone for image processing or remote control tasks.

---

## 💻 Software Support

1. **Arduino IDE with Required Libraries**  
   - Easy-to-use environment for programming the CVPro bot.  
   - Supports object detection, motor control, and sensor interfacing.

2. **Android Mobile App for WRO Round 2**  
   - AI-driven object detection for red and green boxes.  
   - Supports custom object detection and image classification.

---

## 🔧 Technical Notes

### About the CVPro Controller

- **Charging and Discharging**:  
  Charging is allowed **only when the robot is OFF** to ensure safety.  

- **Charging Indicators**:  
  - Green LED = Fully charged (visible only when OFF)  
  - Red LED = Charging  
  - Battery lasts ~50 minutes after full charge.

- **Battery**:  
  3.7V, 3200mAh Li-ion single-cell

- **Power Module**:  
  Provides power to the board, sensors, and motors.

- **Motor Driver**:  
  Handles control for DC and servo motors.

- **ESP32 Microcontroller**:  
  Dual-core with Type-C port, supports wired and wireless programming.

### Servo Configuration

- Default center angle: **100°**  
- Operable range: **80° to 120°** (±20°)  
- Going beyond this range may damage the servo.

---

## 📌 Pinouts for CVPro Controller

| Function                     | Port Type | Port No. | GPIO Pins               |
|-----------------------------|-----------|----------|--------------------------|
| DC Motor                    | USB 3.0   | 1        | 32, 33                   |
| F1US & F2US (Front US)      | USB 3.0   | 2        | F1 - 16,14 / F2 - 25,26  |
| BUS (Back US)               | USB 3.0   | 3        | 17, 19                   |
| SM (Servo Motor)            | USB 3.0   | 4        | 27                       |
| RUS & LUS (Right & Left US) | USB 3.0   | 5        | Right - 2,23 / Left - 5,18|
| FUS (Front US)              | USB 2.0   | 6        | 12, 4                    |
| CS (Color Sensor)           | USB 2.0   | 7        | 22, 21                   |
| RGB LED                     | -         | -        | 15                       |
| NSLEEP for Motor            | -         | -        | 13                       |
| Battery Voltage             | -         | -        | 39                       |
| DPDT Push Button            | -         | -        | 34                       |
| Optical Encoder             | -         | -        | 36                       |

---

## 🔌 Connecting Mobile Phone to CVPro Controller

To establish a proper connection:

1. **Type-C OTG Cable Setup**:  
   Connect the female end of the Type-C OTG cable to the male end of the Type-C USB cable.

2. **To Mobile Phone**:  
   Plug the Type-C OTG end into your phone.

3. **To CVPro Controller**:  
   Plug the USB Type-C end into the controller's Type-C port.

4. **Grant Permissions**:  
   Your phone will prompt for permission. Tap **“Allow”** to enable the connection.

---

## 🧪 Working Procedure

### Step 1: Download Bot Test Codes  
🔗 [CVPro GitHub Repository](https://github.com/robotixdevteam/CVPro_Competition_Kit/tree/main)

### Step 2: Install Arduino IDE

Follow: 🔗 [Arduino Installation Guide](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE)

#### For Windows:
- Visit: https://www.arduino.cc/en/software  
- Download: **"Windows Win 10 and newer, 64 bits"**  
- Set **Upload Speed** to **115200** in Tools menu

#### For macOS:
- Visit: https://www.arduino.cc/en/software  
- Download: **"macOS Intel, 10.15 'Catalina' or newer"**  
- Set **Upload Speed** to **115200**

#### For Ubuntu/Linux:
- Visit: https://www.arduino.cc/en/software  
- Download: **Linux AppImage (X86-64)**  
- Make executable:
  ```bash
  chmod +x <filename>.AppImage
