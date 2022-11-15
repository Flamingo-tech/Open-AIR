# Open AIR Mini
Opensource firmware and hardware for home ventilation boxes


Goals of the project:
 - Open source hardware and software.
 - WI-FI enabled by default.
 - Fully controllable by Home assistant.
 - If themperature outside < inside use the home ventilation system to cool the inside of my house.
 - sensors need to be backwards compatible with Duco sensors.
 - Must work with different home ventilation boxes.


# Open Duco Mini
![image.png](https://flamingo-tech.nl/wp-content/uploads/2021/11/image-5-1024x642.png)
 - Support for two sensors on the main board itself.
 - Wifi Support.
 - Home assistant integration via ESPhome interface.
 - Two sensor connectors
 
# Support
The Open AIR Mini works with the following ventilation boxes:
 - DucoBox Silent Standard
 - DucoBox Silent Perilex
 - DucoBox Silent Connect
 - DucoBox Focus (Warning: Original Duco Valves are not supported!)
 - Orcon MVS-15RH
 - and more (see schematic below)
 
 If your home ventilation motor supports the following connections (See image below) Then you can use the Open Air Mini
 ![image.png](https://www.flamingo-tech.nl/wp-content/uploads/2022/11/EBM2.png) 
 
The following pins need to be available:

230 Vac directly to the motor
 - 1 Protective earth
 - 2 Power Supply 230VAC 50-60Hz
 - 3 Neutral conductor
 
 Control cabeling:
 - 4 GND (on ebmpapst motors BLUE)
 - 5 Tach output (on ebmpapst motors WHITE)
 - 6 10V Output (on ebmpapst motors RED)
 - 7 0-10V PWM Input ((on ebmpapst motors YELLOW)
 
 

# Important:
This project is not supported by Duco and or Orcon the company nor is there any affiliation with these companies. 


