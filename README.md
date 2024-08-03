# Open AIR

Open AIR is an open-source solution for home ventilation and management through Home Assistant integration. The objective of this project is to develop a versatile ecosystem of Home Assistant-compatible devices that can be easily installed in a wide variety of off-the-shelf ventilation systems, allowing seamless integration into your smart home setup.

The OpenAIR ecosystem is designed to offer the following capabilities:

* Humidity measurement within air ducts
* CO2 level detection in air ducts
* Temperature monitoring inside air ducts
* Default Wi-Fi connectivity
* Full compatibility and control with Home Assistant out of the box
* Adherence to open-source principles

The long-term vision for this project is to create a fully open-source ventilation system that can be 3D printed, preferably using recycled plastics as the primary material.

#### Open AIR Mini:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Mini/Pictures/Open_AIR_Mini_V1.4.1_ALTIUM.png"/>
</p>

The OpenAIR Mini is a versatile, open-source ventilation controller designed to be compatible with a range of popular ventilation units, including but not limited to:

* DucoBox Silent Standard
* DucoBox Silent Perilex
* DucoBox Silent Connect
* DucoBox Focus (⚠ Note: Original Duco Valves are not supported! ⚠)
* Orcon MVS-15RH
    
Example intergration in HA:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Mini/Pictures/Open_AIR_Mini_HA_Integration.jpg"/>
</p>

For more information about the Open AIR Mini see: [Open AIR Mini](https://github.com/Flamingo-tech/Open-AIR/tree/main/Open%20Air%20Mini) 

#### Open AIR Valve:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Valve/Hardware/Pictures/Installed_Valves_Example.png"/>
</p>

The Open AIR Valve is an open-source valve designed to work with several Duco ventilation boxes, including the DucoBox Silent Standard, DucoBox Silent Perilex, DucoBox Silent Connect, and DucoBox Focus (Note: Original Duco Valves are not supported). It can be fully controlled from Home Assistant, allowing you to set any value between 0-100% open or closed. Additionally, the valve can be connected to one sensor. 

Example intergration in HA:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Valve/Hardware/Pictures/Open_AIR_Valve_HA_Example.png"/>
</p>


In the future, an external enclosure will be developed for the OpenAIR Valves. This housing can be conveniently installed alongside any ventilation unit, positioned between the unit and the air duct for seamless integration.

For more information about the Open AIR Valve see: [Open AIR Valve](https://github.com/Flamingo-tech/Open-AIR/tree/main/Open%20AIR%20Valve) 

#### Open AIR Sensors
 TODO

# Progress:


|   Part:                     |Done: |Version:    |Duco Part Number:|Backwards compatible:|Active:|Store Link:|
|:----------------------------|:-----|:-----------|:----------------|:--------------------|:------|:----------|
|Open AIR Mini                |✔️    |V1.3.0      | -               |✔️                     |✔️    |[Click](https://www.tindie.com/products/theflamingo/open-air-mini-v130/) 
|Open AIR Pro                 |❌    |-           |-                |-                      |❌    |
|Moisture Sensor              |✔️    |V2.0.0      | 0000-4218       | ✔️                    |✔️    |[Click](https://www.tindie.com/products/theflamingo/open-air-humidity-sensor/)
|CO2 Sensor                   |✔️    |V2.1.0      | 0000-4216       | ✔️                    |❌    |
|Sense Board (RH,Co2,VOC, NOx)|✔️    |V1.0.0      | -               | ❌                    |✔️    |[Click](https://www.tindie.com/products/theflamingo/open-air-sense-board/)
|Programmer                   |✔️    |V1.1.0      | -               | ✔️                    |✔️    |
|Open AIR Valve               |✔️    |V1.3.0      |-                |❌                     |✔️    |[Click](https://www.tindie.com/products/theflamingo/open-air-valve/)
|External Open AIR Valve      |❌    |❌          |-                |❌                     |❌    |          


# Backwards Compatibility

If there is a checkmark in the 'Backwards Compatible' column of the table above, it indicates that you can use the specified device in conjunction with the original Duco Silent ventilation box. For example, you can replace the original Duco moisture/humidity sensor with one of our offerings.

# Special thanks:
[@thomasvnl](https://github.com/thomasvnl) For writing the Valve firmware and valuable feedback.\
[@Septillion](https://github.com/septillion-git) Thanks for providing valuable feedback.\
[@KristofRobberechts ](https://github.com/KristofRobberechts) For providing a beautiful valve design!\
[@slurpgeit](https://github.com/Slurpgeit) Helping write new firmware for the SHT-21 sensor + button software for the Open AIR Mini.

D.Smith For the first version of the installation manual
