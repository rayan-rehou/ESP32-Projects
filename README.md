# ESP32 Projects

ESP32 projects I built and tested on a real breadboard, programmed in C++ with the Arduino framework (Arduino IDE, board: **ESP32 Dev Module**).

![Sensor-triggered traffic light controller running on the real board](https://rayan-rehou.github.io/smart-traffic-light-demo.gif?v=1)

| Project | What it does | Demo |
|---|---|---|
| [Sensor-Triggered Traffic Light Controller](sensor-triggered-traffic-light-controller/) | Two streets with 6 LEDs. An ultrasonic sensor detects a waiting car, a buzzer beeps, an I2C LCD shows a message, and the lights change safely | [Watch and try it](https://rayan-rehou.github.io/#smartlight) |
| [Joystick Motor Control](joystick-motor-control/) | A joystick drives a stepper motor: faster the further you push, stops in a dead zone, tracks the angle, stops at ±180° and sets zero with a click | [Watch and try it](https://rayan-rehou.github.io/#jogctl) |
| [Water Cup Level Indicator](water-cup-level-indicator/) | An ultrasonic sensor above a cup measures the water, an I2C LCD shows the height and fill level live, and a red LED and buzzer warn at 80 % before it overflows | [Watch and try it](https://rayan-rehou.github.io/#watercup) |
| [Wi-Fi LED Controller](wifi-led-controller/) | The ESP32 hosts a web page, and a phone turns an LED on, makes it flash, or turns it off | [Watch and try it](https://rayan-rehou.github.io/#wifi) |
| [Multi-Mode LED Animation](multi-mode-led-animation/) | 8 LEDs with two light animations, chosen with 3 push buttons or from a computer over USB serial | [Watch and try it](https://rayan-rehou.github.io/#led) |
| [Basic Traffic Light](basic-traffic-light/) | Push buttons start and stop a green → yellow → red LED sequence | [Watch and try it](https://rayan-rehou.github.io/#traffic) |

## Hardware

- ESP32 DevKit
- Breadboard and jumper wires
- LEDs with 220 Ω resistors
- 1 kΩ resistors (voltage divider for the sensor's 5 V Echo signal)
- Push buttons
- HC-SR04 ultrasonic sensor
- Active buzzer
- 16×2 LCD with an I2C backpack
- HW-504 joystick module
- 28BYJ-48 stepper motor with a ULN2003 driver board

## What I practiced

- Digital outputs (LEDs) and inputs (buttons with `INPUT_PULLUP` and `INPUT_PULLDOWN`)
- Timing with `delay()` and, for the Wi-Fi controller, non-blocking timing with `millis()`
- Receiving commands from a computer over USB serial
- Wi-Fi on the ESP32: creating an access point and serving a web page on port 80
- Measuring distance with an ultrasonic sensor and `pulseIn()`
- Bringing a 5 V signal down to 3.3 V with a voltage divider, and calibrating a sensor with real measurements
- Reading a joystick with the ADC (`analogRead`), setting a dead zone, and turning it into a speed with `map()`
- Driving a stepper motor with a 4-step coil sequence, counting steps to track the angle, and adding ±180° limits
- I2C communication with an LCD on custom pins (`Wire.begin(16, 17)` and `Wire.begin(18, 5)`)
- Debugging real hardware: pin conflicts, power issues, and timing bugs

These are the building blocks for my **Smart Temperature Monitor**, which reads a DHT22 sensor and sends its readings online.

Portfolio: [rayan-rehou.github.io](https://rayan-rehou.github.io)
