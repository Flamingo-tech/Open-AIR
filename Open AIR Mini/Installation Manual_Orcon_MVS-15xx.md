 # Easy installation Manual For Open AIR Mini for Orcon MVS-15xx

 **Special thanks to D.Smith for helping and inspiring me for writing this :)!**

 This guide assumes you've chosen the **pre-programmed** option when you've bought the Open AIR Mini. This guide will guide you trough the installation/Home Assistant proces.

 ## Introduction

The Open Air Mini is an innovative electronic circuit intended to replace the existing circuitry in your ventilation box. It is a product of an open-source endeavor aimed at giving you the power to control your preferred mechanical ventilation unit through your home automation system.

Typically, ventilation boxes, like those from DUCO or ORCON, can have their circuit boards upgraded with the Open Air Mini. This modification enables you to control your ventilation using a home automation system or even through a web browser.

The typical use case is to implement demand-driven ventilation. This system measures air quality factors such as CO2 and moisture. Based on these measurements, it adjusts the ventilation in your home. Consequently, it promotes energy efficiency by pausing the ventilation system's motor when not needed, and preventing the unnecessary expulsion of warm air from your home.

The Open Air Mini not only contributes to energy-saving but also provides freedom from vendor lock-in. It operates independently of cloud services and ensures your statistics remain private. It's a perfect blend of convenience, efficiency, and privacy.

**Important Notice**
Please be aware that this project operates independently and does not have support or affiliation with Duco, Orcon, or any other vendor. Moreover, there is no technical assistance available from these companies. If you choose to modify your ventilation box using the Open Air Mini, it is a decision made solely at your discretion and assumed risk. Remember, undertaking modifications implies accepting full responsibility for any potential consequences.


 ## Installation in a Orcon MVS-15xx

 The installation proces is done in 7 easy steps!

 1. Locating Your Orcon MVS-15xx
 2. Remove Power
 3. Remove Original Hardware
 4. Insert Open AIR Mini
 5. Connect your Open AIR Mini
 6. Powering up Your Open AIR Mini
 7. Adding the Open AIR Mini to Home Assistant

# 1 Locating Your MVS-15xx Silent

The location of your ventilation box can vary within your home. We encourage you to locate it. As a homeowner, this task should be straightforward and can be quite an enlightening step in familiarizing yourself further with your home's infrastructure. ;)
Please remove the white cover. You will be greated with:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Mini/Pictures/1_Orcon.jpg"/>
</p>

The cover may prove challenging to detach as it is secured by four semi-circular white components (on the sides of the box). I managed to wedge a screwdriver beneath these parts. This action revealed the inner workings of Orcon ventilation box.

# 2 Remove Power

It is critical to disconnect your Orcon ventilation before proceeding. This step is extremely important. **Neglecting to do so could result in severe injury or even death. Make sure to cut off all power supply.**

Ensure, then doubly ensure, that you've disconnected the correct plug. It's better to check multiple times than risk an accident.

If you're unsure about any aspect of these steps or find them confusing, don't hesitate to seek help. You might ask someone who's more familiar with the process, or consider hiring a professional. Safety should always be your top priority.

Proceed to detach the cables from the original Orcon hardware:
For the two big connectors you need to pinch the white tab. For the smaller four pin connector, just pull.
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Mini/Pictures/2_Orcon.jpg"/>
</p>


# 3. Remove Original Hardware

Push the two tabs on the side, and pull the board up. It should lift right up.
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Mini/Pictures/3_Orcon.jpg"/>
</p>


Be sure to safely store the original circuit board after removal. If you ever decide to sell or rent your house in the future, you'll have the option to reinstall the original Orcon hardware. Its availability will provide flexibility for future circumstances.

# 4. Insert Open AIR Mini

For the installation of the Open AIR Mini, position it as follows:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Mini/Pictures/4_Orcon.jpg"/>
</p>

Gently pull the tabs to the side again and slide the Open AIR Mini in place.

# 5. Connect your Open AIR Mini

To provide power to your Open Air Mini, you'll need to connect the power cable to the white connector labled "Power Input". 
To provide power to your Orcon Motor, you'll need to connect the power cable to the white connector labled "Motor Output". 

Please pay close attention to the sequence in which the cables need to be connected:
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Mini/Pictures/5_Orcon.jpg"/>
</p>

Once all the cables are connected, make it a point to give each of them a gentle pull. This is to doubly ensure that they are firmly and correctly connected, providing a secure foundation for optimal operation.

# 6. Powering up Your Open AIR Mini

Reconnect the power plug to your Orcon box. You should now see a multitude of green LEDs light up.
Ensure that all five LEDs at the top of the circuit board are illuminated. If any of them are not on, please reach out to me at flamingo-tech@protonmail.com for assistance.
If you have the **pre-programmed option**, the ESPHome LED (marked by the lower green LED) should be blinking.

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
<p align="center">
  <img src="https://github.com/Flamingo-tech/Open-AIR/blob/main/Open%20AIR%20Mini/Pictures/13.png"/>
</p>

Next, select your network and input your credentials. After this step, the device will undergo a reboot process, which may take approximately 4-5 minutes. Once completed, you should be able to see your Home Assistant (HA) environment directly, ensuring a smooth setup process.

Should you encounter any difficulties and the process fails for some reason, you have the option to manually reset the device using the reset button. If the fallback hotspot reappears, this suggests that the Open AIR Mini was unable to establish a connection with your network. In such a case, please attempt the process again.

It's worth noting that if you're utilizing a hidden SSID you cant use the pre-programmed option!


Upon successful completion of these steps, your Home Assistant should generate a "New Devices Discovered" notification. To proceed, click on the "Check it Out" option, then select the "Configure" button on the new ESPHome device. A pop-up window should appear next; hit the "Submit" button.

Congratulations, you're all set! You can now begin creating custom automations for your device. Enjoy exploring the possibilities this brings to your home environment.

**After adding the Open AIR Mini to a dashboard long press the fan logo and then you can change the RPM**

Have fun :)