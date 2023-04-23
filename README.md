# Open AIR

Open AIR is an open-source system for home ventilation and control via Home Assistant. The goal of this project is to create an ecosystem of these Home Assistant compatible devices that can be installed in a wide variaty of of-the-shelf ventilation boxes/devices so you can incorporate them into your own smart home system.

The Open AIR ecosystem must be able to do the following:
 - Measure humidity in an air duct
 - Measure CO2 in an air duct
 - Measure tmperature in an air duct
 - Be WiFi enabled by default
 - Be fully controllable by Home Assistant out of the box
 - Comply to open-source standards

The long-term goal for this project is create a completely open-source venilation box which can be 3D printed (preferably out of recycled plastics).

#### Open AIR Mini:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/image-5-1568x983.png?raw=true"/>
</p>

The Open AIR Mini is an open-source ventilation controller that works with at least the following ventilation boxes:
- DucoBox Silent Standard
- DucoBox Silent Perilex
- DucoBox Silent Connect
- DucoBox Focus (⚠ Warning: Original Duco Valves are not supported! ⚠)
- Orcon MVS-15RH

Example intergration in HA:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/BJEXNSvmAE3wAsKvwCHGmWnx.webp"/>
</p>

For more information about the Open AIR Mini see: [Open AIR Mini](https://github.com/Flamingo-tech/Open-AIR/tree/main/Open%20Air%20Mini) 

#### Open AIR Valve:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Valve/Hardware/AIR-Valve.jpeg?raw=true"/>
</p>

The Open AIR Valve is an open-source valve that works with the following ventilation boxes:
- DucoBox Silent Standard
- DucoBox Silent Perilex
- DucoBox Silent Connect
- DucoBox Focus (⚠ Warning: Original Duco Valves are not supported! ⚠)

Example intergration in HA:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Valve/Hardware/cMMb3mzwEilepQ762TXY6zFK.png?raw=true"/>
</p>


In the future an external housing will be made for the Open AIR Valves. This can then be installed next to any ventilation box, between it and the air duct.

For more information about the Open AIR Valve see: [Open AIR Valve](https://github.com/Flamingo-tech/Open-AIR/tree/main/Open%20AIR%20Valve) 

#### Open AIR Sensors
 TODO

# Progress:


|   Part:         |Done:	                         |Version:                       |Duco Part Number|Backwards compatible|
|----------------|-------------------------------|-----------------------------|-----------------------------|-----------------------------|
|Open AIR Mini|✔️         |V1.2          | -|✔️ 
|Open AIR Pro         |❌|-|- |
|Moisture Sensor        |✔️            |V2.0        | 0000-4218 | ✔️|
|CO2 Sensor         |✔️|V2.1| 0000-4216 | ✔️
|All-In-One Sensor         |✔️|V2.1| - | ❌ 
|Programmer         |✔️|V1.0| - | ✔️ 
|Open AIR Valve         |✔️|V1.2|- |❌
|External Open AIR Valve         |❌|❌|- |❌
|Open AIR Ventilation Box         |❌|❌|- |❌

# Backwards Compatibility

If the table above has a checkmark in the `Backwards compatible` column, then you can use the device in conjuction with the original Duco Silent ventilaton box i.e. instead of an original moisture/humidity sensor made by Duco, you could use one of ours.


# Special thanks:
[@thomasvnl](https://github.com/thomasvnl) For writing the Valve firmware and valuable feedback.\
[@Septillion](https://github.com/septillion-git) Thanks for providing valuable feedback.\
[@KristofRobberechts ](https://github.com/KristofRobberechts) For providing a beautiful valve design!
D.Smith For the first version of the installation manual
