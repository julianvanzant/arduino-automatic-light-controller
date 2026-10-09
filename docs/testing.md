# Test and Calibration Log

## Calibration

| Condition | Raw ADC reading | LED PWM command | Notes |
| --- | --- | --- | --- |
| LDR covered | 217 | 218 | Covered with Finger |
| Dim room | 270 | 200 | Covered it by cupping hand |
| Normal room lighting | 497 | 129 |Room isn't that bright naturally|
| Bright direct light | 994 | 0 | Shined phone light |

## Functional checks

- [ ] ADC changes when LDR is covered/uncovered
- [ ] LED brightens when ambient light decreases
- [ ] LCD displays light percentage and PWM value
- [ ] Serial Monitor displays raw ADC and PWM values at 9600 baud
- [ ] Displayed light percentage stays between 0 and 100
- [ ] LED PWM command stays between 0 and 255
- [ ] LCD backlight current limiting checked against module specifications

## Known limitations

- The relative light percentage is not a calibrated lux measurement.
- The LED's brightness is not measured directly; PWM is a command value.
- The current design does not include the DHT11 sensor.
