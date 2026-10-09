# Arduino Automatic Light Controller

An Arduino UNO R3 prototype that uses a photoresistor (LDR) to measure ambient light, automatically adjusts LED brightness with pulse-width modulation (PWM), and displays the relative light level and PWM value on a 16×2 LCD.


## Features
- Analog light sensing through a photoresistor voltage divider
- Inverse light-to-LED PWM control: darker surroundings produce a brighter LED
- Exponential smoothing of ADC readings
- LCD1602 readout of relative light percentage and LED PWM value
- Serial output for debugging at 9600 baud

## Components
- Arduino UNO R3
- Photoresistor (LDR)
- 10 kΩ resistor (LDR voltage divider)
- LED and 220 Ω series resistor
- LCD1602 (parallel interface)
- 10 kΩ potentiometer (LCD contrast)
- Breadboard and jumper wires
- LCD backlight current limiting as required by the particular module

## Connections

### Light sensor and LED

| Component | Connection |
| --- | --- |
| LDR | 5V to A0 |
| 10 kΩ resistor | A0 to GND |
| LED anode | D9 through 220 Ω resistor |
| LED cathode | GND |

The LDR and resistor form a voltage divider. With this orientation, more light generally produces a higher ADC reading.

### LCD1602 (4-bit mode)

| LCD pin | Arduino / supply |
| --- | --- |
| 1 VSS | GND |
| 2 VDD | 5V |
| 3 VO | Center pin of contrast potentiometer (outer pins to 5V and GND) |
| 4 RS | D12 |
| 5 RW | GND |
| 6 E | D11 |
| 11 D4 | D5 |
| 12 D5 | D4 |
| 13 D6 | D3 |
| 14 D7 | D6 |
| 15 A | 5v through a 220Ω resistor to not overdraw current for LED |
| 16 K | GND |

## Firmware

Open [`firmware/automatic_light_controller/automatic_light_controller.ino`](firmware/automatic_light_controller/automatic_light_controller.ino) in Arduino IDE. Select **Arduino UNO** and the correct serial port, then upload.

The sketch uses the `LiquidCrystal` library included with the Arduino IDE.

## How it works

1. The UNO reads the voltage divider on A0 (10-bit ADC, nominally 0–1023).
2. An exponential moving average smooths the readings: `filtered = 0.85 * previous + 0.15 * new`.
3. The filtered ADC value is mapped inversely to an 8-bit PWM command (0–255) on D9.
4. The LCD displays a relative light percentage and the PWM command.
5. Serial Monitor prints the raw ADC and PWM values at 9600 baud.

## Suggested tests

- Cover the LDR and observe the ADC reading, PWM command, and LED.
- Illuminate the LDR and verify the LED dims.
- Verify LCD text updates without leftover characters.
- Record dark and bright ADC readings and adjust calibration constants.
- Check whether the LED illuminates the LDR and causes feedback.

See [`docs/testing.md`](docs/testing.md) for a measurement template.

## Project roadmap

- [x] Assemble the breadboard circuit (reported complete)
- [x] Write integrated Arduino firmware
- [ ] Record calibration data and test results
- [ ] Add photographs of the physical prototype
- [ ] Capture the circuit schematic in KiCad
- [ ] Design and verify the PCB layout
- [ ] Export fabrication files
- [ ] Fabricate and test a physical PCB

## Repository layout

- `firmware/`: Arduino source code
- `docs/`: circuit notes and testing
- `hardware/`: KiCad design files when available
- `images/`: photographs and screenshots when available

## Notes

The DHT11 temperature/humidity sensor was removed from the project after unsuccessful sensor testing. The current project measures ambient light only.
