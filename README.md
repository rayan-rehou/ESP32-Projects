# ESP32 Projects

ESP32 projects I built and tested on a real breadboard, programmed in C++ with the Arduino framework (Arduino IDE, board: **ESP32 Dev Module**).

![Sensor-triggered traffic light controller running on the real board](https://rayan-rehou.netlify.app/smart-traffic-light-demo.gif?v=1)

| Project | What it does | Demo |
|---|---|---|
| [Sensor-Triggered Traffic Light Controller](smart-traffic-light/) | Two streets with 6 LEDs. An ultrasonic sensor detects a waiting car, a buzzer beeps, an I2C LCD shows a message, and the lights change safely | [Watch and try it](https://rayan-rehou.netlify.app/#smartlight) |
| [Multi-Mode LED Animation](multi-mode-led-animation/) | 8 LEDs with two light animations, chosen with 3 push buttons or from a computer over USB serial | [Watch and try it](https://rayan-rehou.netlify.app/#led) |
| [Wi-Fi LED Controller](wifi-led-controller/) | The ESP32 hosts a web page, and a phone turns an LED on, makes it flash, or turns it off | [Watch and try it](https://rayan-rehou.netlify.app/#wifi) |
| [Basic Traffic Light](traffic-light/) | Push buttons start and stop a green → yellow → red LED sequence | [Watch and try it](https://rayan-rehou.netlify.app/#traffic) |

## Hardware

- ESP32 DevKit
- Breadboard and jumper wires
- LEDs with 220 Ω resistors
- Push buttons
- HC-SR04 ultrasonic sensor
- Active buzzer
- 16×2 LCD with an I2C backpack

## What I practiced

- Digital outputs (LEDs) and inputs (buttons with `INPUT_PULLUP` and `INPUT_PULLDOWN`)
- Timing with `delay()` and, for the Wi-Fi controller, non-blocking timing with `millis()`
- Receiving commands from a computer over USB serial
- Wi-Fi on the ESP32: creating an access point and serving a web page on port 80
- Measuring distance with an ultrasonic sensor and `pulseIn()`
- I2C communication with an LCD on custom pins (`Wire.begin(16, 17)`)
- Debugging real hardware: pin conflicts, power issues, and timing bugs

These are the building blocks for my **Smart Temperature Monitor**, which reads a DHT22 sensor and sends its readings online.

Portfolio: [rayan-rehou.netlify.app](https://rayan-rehou.netlify.app)
