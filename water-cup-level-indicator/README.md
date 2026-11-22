# Water Cup Level Indicator

An ESP32 with an HC-SR04 ultrasonic sensor mounted above a cup. It measures the water, shows the height and fill level live on a 16×2 I2C LCD, and turns on a red LED and a buzzer at 80 % to warn before the cup overflows.

**Watch the demo, then try the simulation and the interactive schematic:** [rayan-rehou.netlify.app/#watercup](https://rayan-rehou.netlify.app/#watercup)

Status: built and tested on a real breadboard (November 2026).

## What it does

- The sensor sits above the cup and measures the distance down to the water's surface.
- The ESP32 turns that distance into the water height (cm) and the fill level (%), every 200 ms.
- The LCD shows both live.
- Under 80 %: green LED on. At 80 % or more: red LED on and the buzzer beeps.

## Hardware

- ESP32 Dev Module
- HC-SR04 ultrasonic sensor
- 16×2 LCD with an I2C module (address 0x27)
- Active buzzer
- Green and red LEDs with 220 Ω resistors
- Three 1 kΩ resistors (voltage divider)
- Breadboard and jumper wires

## Wiring

| Component | ESP32 |
|---|---|
| HC-SR04 VCC / GND | VIN (5 V) / GND |
| HC-SR04 Trig | GPIO 22 |
| HC-SR04 Echo | 1 kΩ → GPIO 23, with 2 × 1 kΩ to GND (5 V → 3.3 V divider) |
| LCD SDA / SCL | GPIO 18 / GPIO 5 (custom I2C pins with `Wire.begin(18, 5)`) |
| Buzzer | GPIO 4 |
| Green LED / Red LED | GPIO 19 / GPIO 21 (each with 220 Ω) |

The HC-SR04 runs on 5 V, so its Echo pin outputs 5 V, but ESP32 pins only take 3.3 V. The divider brings it down: 5 V × 2 kΩ ÷ (1 kΩ + 2 kΩ) = 3.33 V.

## How it works

1. The ESP32 sends a 10 µs pulse on Trig, and the sensor sends out an ultrasonic sound.
2. `pulseIn()` measures how long Echo stays HIGH, which is the sound's round trip in µs.
3. Distance (cm) = time ÷ 58
4. Water height = 13.6 − distance
5. Fill level = water ÷ 12 × 100

## Calibration

- Measured with the empty cup: sensor to bottom = 13.6 cm, cup height = 12 cm.
- The alarm is set at 80 % so the water stays out of the sensor's 2 cm blind zone.

## Bugs I fixed

- **Logic levels:** the Echo signal is 5 V, so I built a voltage divider from three 1 kΩ resistors to bring it down to 3.3 V.
- **Stuck at 100 %:** the Trig/Echo pins didn't match the code, then the sensor's VCC/GND wires were missing.
- **Negative readings:** fixed by calibrating the empty-cup distance (13.6 cm) separately from the cup height (12 cm).
- **Buzzer and LEDs not working:** they had no ground connection. Every component needs a path back to GND.

## Files

- [`Water_Cup_Level_Indicator.ino`](Water_Cup_Level_Indicator.ino): the full program (C++, Arduino framework)
