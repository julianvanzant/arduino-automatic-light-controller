# Test and Calibration Log

Fill in actual observations; no measured results have been entered yet.

## Calibration

| Condition | Raw ADC reading | LED PWM command | Notes |
| --- | --- | --- | --- |
| LDR covered | TBD | TBD | |
| Dim room | TBD | TBD | |
| Normal room lighting | TBD | TBD | |
| Bright direct light | TBD | TBD | |

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
