# Open AIR Valve
The Open AIR Valve is an open-source valve designed to work with several Duco ventilation boxes, including the DucoBox Silent Standard, DucoBox Silent Perilex, DucoBox Silent Connect, and DucoBox Focus (Note: Original Duco Valves are not supported). It can be fully controlled from Home Assistant, allowing you to set any value between 0-100% open or closed. Additionally, the valve can be connected to one sensor. 

## The Hardware
![image.gif](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Valve/Hardware/Pictures/Open_AIR_Valve_ASSY.gif?raw=true)

Installed AIR Valve example:
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Valve/Hardware/Pictures/Installed_Valves_Example.png?raw=true)


### Status LEDs
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Valve/Hardware/Pictures/Open_AIR_Valve_Status_LEDS.png?raw=true)

The Open AIR Valve from version V1.3.0 and higher contains five LEDs. The first LED (HOME) indicates the status of the Home switch. When it is on, the valve is closed. The second and third LEDs (Sense LED and Sense LED 2) indicate the 5V and 3.3V sensor power, respectively. The fourth LED (ESP32 LED) indicates the 3.3V power supply for the ESP32, and the fifth LED (Motor) indicates the 12V power supply for the motor. All LEDs (except for the HOME LED, which depends on the position of the valve) should be on during normal operation.


# ⚠ Important

Please note that this project is not supported by Duco and Orcon, and there is no affiliation or technical support from these companies. Modifying your ventilation box is done at your own risk.