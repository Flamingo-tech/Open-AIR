# ESPHome Open AIR Mini

Visit https://esphome.io/ for instructions on how to deploy this firmware.

More documentation might come available in future updates. 

## Before you begin

Make sure to copy `example.secrets.yaml` to `secrets.yaml` and fill it with your own WiFi credentials.

## Different communication busses
Depending on what sensor is connected to what connector you need to declare the uart and/or I<sup>2</sup>C busses. If using one sensor, only one (uart/I<sup>2</sup>C) bus is required. In some cases, multiple busses are required for using multiple sensors with the same hardware id (for I<sup>2</sup>C) or if they do not support a hardware id (for uart).

For example, for uart:
```C++
#choose between:
uart_id: uart_sensor_1 // Only used for the Senseair S8 CO2 sensor
uart_id: uart_sensor_2 // Only used for the Senseair S8 CO2 sensor
```


For example, for I<sup>2</sup>C
```C++
i2c_id: i2c_sensor_1 // Used for RH sensors
i2c_id: i2c_sensor_2 // Used for RH sensors
```
Example:
```yaml
sensor:
  - platform: sht3xd
    i2c_id: i2c_sensor_1
    temperature:
      name: "Temperature Open AIR Mini x"
      id: air_temperature
    humidity:
      name: "Humidity Open AIR Mini x"
      id: air_humidity
    address: 0x44
    update_interval: 60s

#or
sensor:
  - platform: senseair
    uart_id: uart_sensor_1
    co2:
      name: "CO2 Open AIR Mini x"
    update_interval: 60s
```

## Sensors

The following sensors are supported right away, either via ESPHome or via a custom implementation.

1. SHT-31
1. Senseair S8
1. SHT-20

### Sensor Support: SHT-31

More info about this sensor and ESPhome : https://esphome.io/components/sensor/sht3xd.html

If you want to add a SHT-31 moisture & Temperature sensor to the Open AIR Mini, add the following code at the bottom of the `open-air-mini.yaml` file.

```yaml
sensor:
  - platform: sht3xd
    i2c_id: i2c_sensor_1
    temperature:
      name: "Temperature Open AIR Mini x"
      id: air_temperature
    humidity:
      name: "Humidity Open AIR Mini x"
      id: air_humdity
    address: 0x44
    update_interval: 60s
```

### Sensor Support: Senseair S8

More info about this sensor and ESPhome : https://esphome.io/components/sensor/senseair.html?highlight=co2+senseair

If you want to add a Senseair S8 CO2 sensor to the Open AIR Mini, add the following code at the bottom of the `open-air-mini.yaml` file.

```yaml
sensor:
  - platform: senseair
    uart_id: uart_sensor_1
    co2:
      name: "CO2 Open AIR Mini x"
    update_interval: 60s
```

### Sensor Support: SHT-20
⚠️ The original temperature and humidity sensor can only be connected on sensor connector 1, thus using I<sup>2</sup>C bus 1 (which is implicitly used).

If you have a SHT-20 Sensor add the following code at the bottom of `open-air-mini.yaml`

```yaml
sensor:
  - platform: custom
    lambda: |-
      auto sht20 = new SHT20();
      App.register_component(sht20);
      return {sht20->temperature_sensor, sht20->humidity_sensor, sht20->vpd_sensor, sht20->dew_point_sensor};
    sensors:
      - name: "Temperature Open AIR Mini x"
        id: air_temperature
        unit_of_measurement: °C
        accuracy_decimals: 2
      - name: "Humidity Open AIR Mini x"
        id: air_humidity
        unit_of_measurement: "%"
        accuracy_decimals: 2
      - name: "Open AIR Mini x Vapour-pressure deficit"
        id: air_vapor_pressure_deficit
        unit_of_measurement: "kPa"
        accuracy_decimals: 2
      - name: "Open AIR Mini x Dew point"
        id: air_dew_point
        unit_of_measurement: °C
        accuracy_decimals: 2

```

Add the following righ below "board: esp32dev" 
```yaml
  libraries:
    - Wire
    - u-fire/uFire SHT20@^1.1.1
  includes: sht20.h
```

Place the SHT20.H file in the same directory as the `open-air-mini.yaml`.

@[wre](https://github.com/wrenoud) Thanks for your support on this sensor implementation

### Using the Combination Sensor with Senseair S8 & SHT-31 on the same board

If you want to use this specific combination sensor, add the following to the bottom of the `open-air-mini.yaml` file.

```yaml
sensor:
  - platform: sht3xd
    i2c_id: i2c_sensor_1
    temperature:
      name: "Temperature Open AIR Mini x"
      id: air_temperature
    humidity:
      name: "Humidity Open AIR Mini x"
      id: air_humidity
    address: 0x44
    update_interval: 60s
  - platform: senseair
    uart_id: uart_sensor_1
    co2:
      name: "CO2 Open AIR Mini x"
      id: air_co2
    update_interval: 60s
```

###  Notes on using multiple sensors

Change all the 'x' in the document to a number or a letter if you are using multiple sensors and want to be able to clearly identify which is which, and also to prevent conflicts in id namings. If sensors have identical names they wont show up in HA.

## Disconnected Mode

When Home Assistant cannot be reached, either because of a lack of WiFi connection or the Home Assistant server being unavailable, a `disconnected mode` has been added to provide basic functionality to the Open AIR Mini unit. This mode will allow the unit to continue standalone, which in combination with a humidity sensor even allows for different fan speeds activated by humidity levels.

### Disconnected Mode without Humidity Sensor

When the humidity sensor is not connected, the disconnected mode will only allow for the fan to run at a constant speed.

The fan speed can be set in the `open-air-mini.yaml` file by changing the global variable `disconnected_default_fan_speed` to a value between 0 and 100.

To use the Open AIR Mini in disconnected mode without a humidity sensor, in the `open-air-mini.yaml` file, make sure to use the `!include disconnected-mode-without-humidity-sensor.yaml` line in the `script` section. Make sure that the other include is commented out.

### Disconnected Mode With Humidity Sensor

When the humidity sensor is connected, the disconnected mode will allow for the fan to run at a variable speed based on the humidity level.

The different fan speeds and thresholds can be set in the `open-air-mini.yaml` file by changing the global variables that correspond to the different fan speeds and humidity thresholds (see inline comments).

To use the Open AIR Mini in disconnected mode with a humidity sensor, such a sensor has to be configured in the `open-air-mini.yaml`, and in the `script` section, make sure to use the `!include disconnected-mode-with-humidity-sensor.yaml` line. Make sure that the other include is commented out. The humidity sensor has to be connected to the Open AIR Mini, and the `id` of the humidity sensor has to be `air_humidity`.