# Open AIR Valve

The Open AIR Valve is an open-source valve that is compatible with the following duco ventilation boxes:
DucoBox Silent Standard
DucoBox Silent Perilex
DucoBox Silent Connect
DucoBox Focus (⚠ Warning: Original Duco Valves are not supported! ⚠)


## The Hardware
![image.gif](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Valve/Hardware/Pictures/Open_AIR_Valve_ASSY.gif?raw=true)
The Open AIR Programmer uses a CP2102 chip. To install the drivers for this chip, please click [Here](https://github.com/Flamingo-tech/Open-AIR/tree/main/Open%20AIR%20Programmer/Software) or [Here](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)
The Open AIR Programmer uses a standard USB-C cable to connect to the device. For more information about the pinout of the connector, please check the schematic files.


### Status LEDs
The Open AIR Programmer has three status LEDs: one for active transmit, one for active receive, and a 5V power LED. During normal operation, the 5V LED should be on. When there is a transmit or receive, the TX or RX LED should blink.


# ⚠ Important

Please note that this project is not supported by Duco and Orcon, and there is no affiliation or technical support from these companies. Modifying your ventilation box is done at your own risk.