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
uart_id: uart_sensor_1 // Only used for the Senseair S8 CO2 sensor (Original Duco Co2 Sensor)
uart_id: uart_sensor_2 // Only used for the Senseair S8 CO2 sensor (Original Duco Co2 Sensor)
```


For example, for I<sup>2</sup>C
```C++
i2c_id: i2c_sensor_1 // Used for RH , Co2 , Nox and VOc sensors
i2c_id: i2c_sensor_2 // Used for RH , Co2 , Nox and VOc sensors
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

### New Sensors:
All Open AIR Minis are now shipped with these sensors:
1. [SHT-20](#sensor-support-SHT-20)
1. [SCD-40](#sensor-support-SCD-4X)
1. [SGP-41](#sensor-support-SGP-41)
1. [SCD-40 & SGP-41 Combination Sensor](#SCD-40-&-SGP-41-Combination-Sensor)

### Old Sensors:
1. [SHT-31](#sensor-support-sht-31)
1. [Senseair S8](#sensor-support-senseair-s8)
1. [SHT-31 & Senseair S8 Combination Sensor](#Using-the-Combination-Sensor-with-Senseair-S8-&-SHT-31-on-the-same-board)


## New:

### Sensor Support: SHT-20

If you have a SHT-20 Sensor add the following code at the bottom of `open-air-mini.yaml` 

```yaml
external_components:
  - source: github://dmaasland/esphome@sht2x
    components: [ sht2x ]
```

```yaml
  - platform: sht2x
    i2c_id: i2c_sensor_1
    temperature:
      name: "Open AIR Mini x Temperature"
      id: air_temperature
      accuracy_decimals: 2
    humidity:
      name: "Open AIR Mini x Humidity"
      id: air_humidity
      accuracy_decimals: 2
    update_interval: 30s
```
Thanks @dmaasland : https://github.com/dmaasland/esphome/tree/sht2x/esphome/components/sht2x

### Sensor Support: SCD-4X

More info about this sensor and ESPhome : https://esphome.io/components/sensor/scd4x.html

If you want to add a SCD-40 moisture & Temperature sensor & Co2 sensor to the Open AIR Mini, add the following code at the bottom of the `open-air-mini.yaml` file.

```yaml
sensor:
  - platform: scd4x
    i2c_id: i2c_sensor_1 
    co2:
      name: "Open AIR Mini x CO2"
      id: air_Co2
      accuracy_decimals: 0
    temperature:
      name: " Open AIR Mini x Temperature"
      id: air_temperature
      accuracy_decimals: 2
    humidity:
      name: " Open AIR Mini x Humidity"
      id: air_humidity
      accuracy_decimals: 2
    update_interval: 30s
    measurement_mode: periodic
```

### Sensor Support: SGP-41

More info about this sensor and ESPhome : https://esphome.io/components/sensor/sgp4x.html & https://esphome.io/components/sensor/scd4x.html

If you want to add a combination sensor SCD-40 moisture & Temperature sensor & Co2 sensor & SGP-41 VOC & NOx to the Open AIR Mini, add the following code at the bottom of the `open-air-mini.yaml` file.

```yaml
sensor:
  - platform: sgp4x
    i2c_id: i2c_sensor_1 
    voc:
      name: "VOC Index Mini x"
      id: air_VOC
    nox:
      name: "NOx Index Mini x"
      id: air_NOx
    compensation:
      temperature_source: air_temperature #Make sure to match these if you change ID's.
      humidity_source: air_humidity       #Make sure to match these if you change ID's.
    update_interval: 30s
```

### Sensor Support: SCD-40 & SGP-41 Combination Sensor

More info about this sensor and ESPhome : https://esphome.io/components/sensor/sgp4x.html

If you want to add a SGP-41 VOC & NOx to the Open AIR Mini, add the following code at the bottom of the `open-air-mini.yaml` file.

```yaml
sensor:
  - platform: scd4x
    i2c_id: i2c_sensor_1
    co2:
      name: "Open AIR Mini Sensor Mini x CO2"
      id: air_Co2
      accuracy_decimals: 0
    temperature:
      name: "Open AIR Mini Sensor Mini x Temperature"
      id: air_temperature
      accuracy_decimals: 2
    humidity:
      name: "Open AIR Mini Sensor Mini x Humidity"
      id: air_humidity
      accuracy_decimals: 2
    update_interval: 30s
    measurement_mode: periodic

  - platform: sgp4x
    i2c_id: i2c_sensor_1 
    voc:
      name: "Open AIR Mini x VOC Index "
      id: air_VOC
    nox:
      name: "Open AIR Mini x NOx Index "
      id: air_NOx
    compensation:
      temperature_source: air_temperature #Make sure to match these if you change ID's.
      humidity_source: air_humidity       #Make sure to match these if you change ID's.
    update_interval: 30s
```


## Old:

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

If you want to add a Senseair S8 Co2 sensor to the Open AIR Valve. Add the following code at the bottom of `open-air-valve.yaml` 

```yaml
sensor:
  - platform: senseair
    uart_id: uart_sensor_1
    co2:
      name: "CO2 Open AIR Mini x"
    update_interval: 60s
```



### Using the Combination Sensor with Senseair S8 & SHT-31 on the same board

If you want to use this specific combination sensor, add the following to the bottom of the `open-air-valve.yaml` file.

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
