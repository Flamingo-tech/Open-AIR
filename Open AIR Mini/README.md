# Open AIR Mini

Open AIR Mini is an open-source project that aims to provide firmware and hardware for home ventilation boxes. The project has several goals, including open-source hardware and software, Wi-Fi connectivity, full controllability by Home Assistant, temperature-based ventilation, backward compatibility with Duco sensors, and support for different home ventilation boxes.

## The Hardware
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Mini/Pictures/Open_AIR_Mini_V1.4.1_ALTIUM.png"/>
</p>
Open AIR mini installed on DucoBox system:
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Pictures/20240302_122919.jpg?raw=true)
The Open AIR Mini hardware supports two sensors on the main board, Wi-Fi connectivity, Home Assistant integration via the ESPHome interface, OTA support, two sensor connectors, a robust power design, and status LEDs. The device is installed by connecting it to the ventilation box, and it can work with different home ventilation boxes. 

Open AIR mini installed on Orcon system:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Mini/Pictures/20240302_124957.jpg"/>
</p>
Since version V1.4.0 the Open AIR Mini can be directly installed in the ORCON MVS-15XX series of boxes. The original Orcon sensors and RF stuff is not supported! However we are working to make all the Open AIR Sensors compatible :)
On the Orcon systems only a single sensor is supported


### Status LEDS
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Pictures/Open_AIR_Mini_LEDS.png"/>
</p>
The Open AIR Mini from version V1.3.0 and above include five LEDs. The first LED (AC/DC) indicates the status of the Meanwell AC-> DC Converter, and if it is off, the device has no 230VAC power. The second and third LEDs (Sense LED and Sense LED 2) indicate the 5V and 3.3V sensor power, respectively. The fourth LED (ESP32 LED) indicates the 3.3V power supply for the ESP32, and the fifth LED (Motor) indicates the 10V output from the motor. All LEDs should be on in normal operation. 

The ESP32 has a status LED located under it, which displays three different statuses. It blinks slowly (about every second) when a warning is active, blinks quickly (multiple times per second) when an error is active, and stays off otherwise.

## Supported Ventilation Boxes
⚠No RF devices are supported⚠
The Open AIR Mini works with the following ventilation boxes:
 - DucoBox Silent Standard
 - DucoBox Silent Perilex
 - DucoBox Silent Connect
 - DucoBox Focus (Warning: Original Duco Valves are not supported!)
 - Orcon MVS-15xx
 - and more (see schematic below)
 
 If your home ventilation motor supports the following connections (See image below) Then you can use the Open Air Mini
 ![image.png](https://www.flamingo-tech.nl/wp-content/uploads/2022/11/EBM2.png) 
 
The following pins need to be available:

230 Vac directly to the motor
 - 1 Protective earth
 - 2 Power Supply 230VAC 50-60Hz
 - 3 Neutral conductor
 
 Control cabling:
 - 4 GND (on ebmpapst motors BLUE)
 - 5 Tach output (on ebmpapst motors WHITE)
 - 6 10V Output (on ebmpapst motors RED)
 - 7 0-10V PWM Input (on ebmpapst motors YELLOW)
 

# ⚠ Important

Please note that this project is not supported by Duco and Orcon, and there is no affiliation or technical support from these companies. Modifying your ventilation box is done at your own risk.
