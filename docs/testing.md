# Test and Calibration Log

## Calibration

| Condition | Raw ADC reading | LED PWM command | Notes |
| --- | --- | --- | --- |
| LDR covered | 217 | 218 | |
| Dim room | 270 | 200 | |
| Normal room lighting | 497 | 129 | |
| Bright direct light | 994 | 0 | |

Use the observed ADC readings to update `darkReading` and `brightReading` in the firmware. Keep `darkReading < brightReading` for the present LDR wiring.

## Functional checks

- [ ] ADC changes when LDR is covered/uncovered
- [ ] LED brightens when ambient light decreases
- [ ] LCD displays light percentage and PWM value
- [ ] Serial Monitor displays raw ADC and PWM values at 9600 baud
- [ ] Displayed light percentage stays between 0 and 100
- [ ] LED PWM command stays between 0 and 255
- [ ] LCD backlight current limiting checked against module specifications

## Photos

Add your own circuit photos under `images/` and link them from the README.

## Known limitations

- The relative light percentage is not a calibrated lux measurement.
- The LED's brightness is not measured directly; PWM is a command value.
- The current design does not include the DHT11 sensor.
