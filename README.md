# GreenMetaCity2025-SolarTracker
Repository for Team 1 of the GreenMetaCity Challenge 2025 organized by the EELISA chapter @ Friedrich-Alexander-Universität, Erlangen-Nürnberg

Thanks for the details! Below is a sample README file for your GitHub repository based on the components you've provided:

---

# Solar Tracker System

This project aims to create an automatic solar panel tracker that adjusts the panel's position based on light intensity. The system uses various sensors and components integrated with an Arduino UNO to monitor environmental conditions and move the solar panel accordingly.

## Components Used

### 1. **Solar Panel**
   - The solar panel collects solar energy and converts it into electrical power. In this project, its orientation is adjusted to ensure it receives maximum sunlight, improving energy efficiency.

### 2. **Light Intensity Sensor (BH1750)**
   - The BH1750 light sensor measures ambient light levels in lux. It communicates with the Arduino via the I2C bus and provides the light intensity data, which helps determine the direction in which the solar panel should be oriented.

### 3. **3x Photoresistors (LDRs)**
   - Three photoresistors are placed at 0, 90, and 180 degrees on the solar panel assembly. These sensors detect the light intensity at different angles and provide feedback to adjust the panel's position towards the brightest area.
   - **Photoresistor 0°** – Connected to Analog Pin A0.
   - **Photoresistor 90°** – Connected to Analog Pin A1.
   - **Photoresistor 180°** – Connected to Analog Pin A2.

### 4. **Humidity & Temperature Sensor (DHT11)**
   - The DHT11 sensor provides both temperature and humidity readings. These data can be used for environmental monitoring, though in this project, it serves more as an additional input alongside the light sensors.

### 5. **LCD Screen (16x2 I2C)**
   - A 16x2 LCD screen is used to display real-time sensor data (such as temperature, humidity, and light intensity) and provide feedback to the user. It uses the I2C communication protocol to minimize the number of pins needed for connection.

### 6. **Arduino UNO**
   - The central microcontroller that controls all components in the system. It reads data from the sensors, controls the servo motors to adjust the panel’s position, and displays relevant information on the LCD screen.

## Features

- **Automatic Solar Panel Tracking**: The system moves the solar panel towards the brightest light source using the feedback from the photoresistors.
- **Real-Time Data Display**: The LCD screen shows live data from the sensors, such as temperature, humidity, and light intensity.
- **Efficient Power Management**: By continuously tracking sunlight, the system optimizes the angle of the solar panel, ensuring that it receives the maximum amount of sunlight throughout the day.

## Installation

1. **Hardware Setup**:
   - Connect the components to the Arduino UNO as per the following pin connections:
     - **Light Intensity Sensor**: I2C communication (SDA to A4, SCL to A5)
     - **Photoresistors**: A0, A1, A2
     - **DHT11 Sensor**: Digital Pin 8
     - **LCD Screen**: I2C (SDA to A4, SCL to A5)
     - **Servos**: Digital Pins 9 (Base rotation) and 10 (Tilt adjustment)

2. **Software Setup**:
   - Install the required libraries:
     - Servo library (for controlling servo motors)
     - BH1750 library (for the light intensity sensor)
     - DHT11 library (for temperature and humidity sensor)
     - LiquidCrystal_I2C library (for LCD screen)

   - Open the Arduino IDE, paste the provided code into the IDE, and upload it to the Arduino UNO.

## Code Overview

The provided code reads the light intensity from the photoresistors and the light intensity sensor, checks which direction has the brightest light, and adjusts the solar panel's position accordingly. It also reads temperature and humidity data from the DHT11 sensor and displays all the data on the LCD screen.

---

### Example Output on LCD:

```
Max Light: 512
Angle: 90
```

This display shows the current light intensity and the angle at which the panel is positioned based on the sensors.

## Troubleshooting

- **LCD Not Displaying Data**: Ensure the I2C connections are correct. Try running a simple I2C scan to verify communication.
- **Servo Motors Not Moving**: Check the power supply to the servos and ensure there are no mechanical blockages.
- **Sensor Readings are Incorrect**: Ensure that all sensors are properly connected and functioning.

## License

This project is licensed under the MIT License.

---

You can add more details depending on your needs. Once you're happy with the content, you can copy this into a `README.md` file and upload it to your GitHub repository. Let me know if you'd like any more changes!