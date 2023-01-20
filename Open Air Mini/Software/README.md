# ESPHome Open AIR Mini

Visit https://esphome.io/ for instructions on how to deploy this firmware.

More documentation might come available in future updates. Make sure to copy `example.secrets.yaml` to `secrets.yaml` and fill it with your own wifi credentials.

### Sensor 1/2
Depending on what sensor is connected to what connector you need to declare the uart/I2C bus.
```
#choose between:
uart_id: uart_sensor_1 //used for Co2 Sensor only
uart_id: uart_sensor_2 //used for Co2 Sensor only

and/or:
i2c_id: i2c_sensor_1 //used for RH Sensor only
i2c_id: i2c_sensor_2 //used for RH Sensor only
```
Example:
```
sensor:
  - platform: sht3xd
    #add sensor I2C bus here
    temperature:
      name: "Temperature Open AIR Mini x"
    humidity:
      name: "Humidity Open AIR Mini x"
    address: 0x44
    update_interval: 60s

#or
sensor:
  - platform: senseair
    #add sensor UART bus here
    co2:
      name: "Co2 Open AIR Mini x"
    update_interval: 60s
```

### Sensor Support: SHT-31

More info about this sensor and ESPhome : https://esphome.io/components/sensor/sht3xd.html

If you want to add a SHT-31 moisture & Temperature sensor to the Open AIR Mini. Add the following code at the bottom of `open-air-mini.yaml` 

```
sensor:
  - platform: sht3xd
  #add sensor I2C bus here
    temperature:
      name: "Temperature Open AIR Mini x"
    humidity:
      name: "Humidity Open AIR Mini x"
    address: 0x44
    update_interval: 60s
```

### Sensor Support: Senseair S8

More info about this sensor and ESPhome : https://esphome.io/components/sensor/senseair.html?highlight=co2+senseair

If you want to add a Senseair S8 Co2 sensor to the Open AIR Mini. Add the following code at the bottom of `open-air-mini.yaml` 

```
sensor:
  - platform: senseair
  #add sensor I2C bus here
    co2:
      name: "Co2 Open AIR Mini x"
    update_interval: 60s
```

### Combination of Senseair S8 & SHT-31 in one Sensor

If you have a combination sensor add the following to the bottom of `open-air-mini.yaml` 

```
sensor:
  - platform: sht3xd
    #add sensor I2C bus here
    temperature:
      name: "Temperature Open AIR Mini x"
    humidity:
      name: "Humidity Open AIR Mini x"
    address: 0x44
    update_interval: 60s
  - platform: senseair
    #add sensor UART bus here
    co2:
      name: "Co2 Open AIR Mini x"
    update_interval: 60s
```

### SHT-20 Sensor

If you have a SHT-20 Sensor add the following code at the bottom of `open-air-Mini.yaml` 

```
sensor:
  - platform: custom
    lambda: |-
      auto sht20 = new SHT20();
      App.register_component(sht20);
      return {sht20->temperature_sensor, sht20->humidity_sensor, sht20->vpd_sensor, sht20->dew_point_sensor};
    sensors:
      - name: "Temperature Open AIR Mini x"
        id: sensor_temperature
        unit_of_measurement: °C
        accuracy_decimals: 2
      - name: "Humidity Open AIR Mini x"
        id: sensor_humidity
        unit_of_measurement: "%"
        accuracy_decimals: 2
      - name: "Open AIR Mini x Vapour-pressure deficit"
        id: sensor_vpd
        unit_of_measurement: "kPa"
        accuracy_decimals: 2
      - name: "Open AIR Mini x Dew point"
        id: sensor_dew_point
        unit_of_measurement: °C
        accuracy_decimals: 2

```
Add the following righ below "board: esp32dev" 
```
  libraries:
    - Wire
    - u-fire/uFire SHT20@^1.1.1
  includes: sht20.h
```

Place the SHT20.H file in the same directory as the `open-air-Mini.yaml`.
Thanks 

@[wre](https://github.com/wrenoud) Thanks for your support on this sensor implementation

Change all the 'x' in the document for a number or a letter so you know which sensor is which. (if sensors have identical names they wont show up in HA)
