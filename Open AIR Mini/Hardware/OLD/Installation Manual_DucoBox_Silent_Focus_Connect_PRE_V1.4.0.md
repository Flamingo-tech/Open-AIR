 # Easy installation Manual For Open AIR Mini

 **Special thanks to D.Smith for helping and inspiring me for writing this :)!**

 This guide assumes you've chosen the **pre-programmed** option when you've bought the Open AIR Mini. This guide will guide you trough the installation/Home Assistant proces.

 ## Introduction

The Open Air Mini is an innovative electronic circuit intended to replace the existing circuitry in your ventilation box. It is a product of an open-source endeavor aimed at giving you the power to control your preferred mechanical ventilation unit through your home automation system.

Typically, ventilation boxes, like those from DUCO or ORCON, can have their circuit boards upgraded with the Open Air Mini. This modification enables you to control your ventilation using a home automation system or even through a web browser.

The typical use case is to implement demand-driven ventilation. This system measures air quality factors such as CO2 and moisture. Based on these measurements, it adjusts the ventilation in your home. Consequently, it promotes energy efficiency by pausing the ventilation system's motor when not needed, and preventing the unnecessary expulsion of warm air from your home.

The Open Air Mini not only contributes to energy-saving but also provides freedom from vendor lock-in. It operates independently of cloud services and ensures your statistics remain private. It's a perfect blend of convenience, efficiency, and privacy.

**Important Notice**
Please be aware that this project operates independently and does not have support or affiliation with Duco, Orcon, or any other vendor. Moreover, there is no technical assistance available from these companies. If you choose to modify your ventilation box using the Open Air Mini, it is a decision made solely at your discretion and assumed risk. Remember, undertaking modifications implies accepting full responsibility for any potential consequences.


 ## Installation in a Ducobox Silent

 The installation proces is done in 7 easy steps!

 1. Locating Your Docubox Silent
 2. Remove Power
 3. Remove Original Hardware
 4. Insert Open AIR Mini
 5. Connect your Open AIR Mini
 6. Powering up Your Open AIR Mini
 7. Adding the Open AIR Mini to Home Assistant

# 1 Locating Your Docubox Silent

The location of your ventilation box can vary within your home. We encourage you to locate it. As a homeowner, this task should be straightforward and can be quite an enlightening step in familiarizing yourself further with your home's infrastructure. ;)
Please remove the white cover. You will be greated with:
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/1.jpg?raw=true)


# 2 Remove Power

It is critical to disconnect your Ducobox Silent before proceeding. This step is extremely important. **Neglecting to do so could result in severe injury or even death. Make sure to cut off all power supply.**

Ensure, then doubly ensure, that you've disconnected the correct plug. It's better to check multiple times than risk an accident.

If you're unsure about any aspect of these steps or find them confusing, don't hesitate to seek help. You might ask someone who's more familiar with the process, or consider hiring a professional. Safety should always be your top priority.
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/2.jpg?raw=true)

Proceed to detach the cables from the original Ducobox hardware:
Press on the orange tabs (highlighted in red in the image provided) and gently pull the wires out from their respective connectors.
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/3.jpg?raw=true)
When done it should look like this:
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/4.jpg?raw=true)

# 3. Remove Original Hardware

Please use a screwdriver to carefully remove the four screws indicated in red in the image provided.
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/5.jpg?raw=true)

Be sure to safely store the original circuit board after removal. If you ever decide to sell or rent your house in the future, you'll have the option to reinstall the original Duco hardware. Its availability will provide flexibility for future circumstances.

# 4. Insert Open AIR Mini

For the installation of the Open AIR Mini, position it as follows:
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/6.jpg?raw=true)
Proceed to secure the Open AIR Mini by reinstalling the screws into the locations indicated in red:
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/7.jpg?raw=true)

# 5. Connect your Open AIR Mini

To provide power to your Open Air Mini, you'll need to connect the power cable to the bottom connector, which is colored green. **This is a crucial step: Press the orange tab and insert the cable simultaneously to ensure a solid connection.**

This process involves pushing the cable in as far as it will go. Once the cable is fully inserted, release the orange tab. Finally, give the cable a gentle pull to confirm it's securely connected. It's essential that the connection is firm to ensure proper operation.
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/8.jpg?raw=true)
Please pay close attention to the sequence in which the cables need to be connected:![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/9.jpg?raw=true)

After this connect the motor power:
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/10.jpg?raw=true)
Please pay close attention to the sequence in which the cables need to be connected:![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/11.jpg?raw=true)

Now connect the motor data cable:
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/12.jpg?raw=true)

Please pay close attention to the sequence in which the cables need to be connected:![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/13.jpg?raw=true)

Once all the cables are connected, make it a point to give each of them a gentle pull. This is to doubly ensure that they are firmly and correctly connected, providing a secure foundation for optimal operation.

# 6. Powering up Your Open AIR Mini

Reconnect the power plug to your Ducobox. You should now see a multitude of green LEDs light up.
Ensure that all five LEDs at the top of the circuit board are illuminated. If any of them are not on, please reach out to me at flamingo-tech@protonmail.com for assistance.
If you have the **pre-programmed option**, the ESPHome LED (marked by the lower green LED) should be blinking.
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/14.jpg?raw=true)

Now you can finally close the ventilation box.

# 7. Adding the Open AIR Mini to Home Assistant

Now open your home assistant page.
If this is the first time using a ESPHOME device:
Go to settings -> Integrations -> Set up a new integration -> Search for esphome.
Now click the esphome intergration and fill in the IP adress of the Home Assistant server. 

Use your mobile phone and or laptop for this step. Please connect to the following network: "Open-AIR-Mini Fallback"
Use this password: "ChangeMe@123!"
Once you've successfully connected to the fallback hotspot using your phone or laptop, opening your browser should direct you to a landing page where you can establish your own network.
If you don't automatically land on this page, you can manually navigate to it by entering the following URL: http://192.168.4.1 in the browser and navigate to it.
Upon reaching this page, you should be greeted with a screen that resembles the following:
![image.png](https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20Air%20Mini/Hardware/OLD/Pictures/15.jpg?raw=true)
Next, select your network and input your credentials. After this step, the device will undergo a reboot process, which may take approximately 4-5 minutes. Once completed, you should be able to see your Home Assistant (HA) environment directly, ensuring a smooth setup process.

Should you encounter any difficulties and the process fails for some reason, you have the option to manually reset the device using the reset button. If the fallback hotspot reappears, this suggests that the Open AIR Mini was unable to establish a connection with your network. In such a case, please attempt the process again.

It's worth noting that if you're utilizing a hidden SSID you cant use the pre-programmed option!


Upon successful completion of these steps, your Home Assistant should generate a "New Devices Discovered" notification. To proceed, click on the "Check it Out" option, then select the "Configure" button on the new ESPHome device. A pop-up window should appear next; hit the "Submit" button.

Congratulations, you're all set! You can now begin creating custom automations for your device. Enjoy exploring the possibilities this brings to your home environment.

**After adding the Open AIR Mini to a dashboard long press the fan logo and then you can change the RPM**

Have fun :)