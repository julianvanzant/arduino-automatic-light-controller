# Hardware / KiCad

Breadboard prototype complete. In progress on KiCad for PCB design

## Intended PCB interface
Arduino signals: 5V, GND, A0, D3, D4, D5, D6, D9, D11, D12.

The PCB should implement:
- LDR and 10 kΩ voltage divider
- LED and series current-limiting resistor
- LCD1602 interface and contrast potentiometer
- Suitable backlight current limiting
- Connectors to the Arduino UNO

Before routing, check actual component dimensions, connector pin order, board power traces, and ERC/DRC.
