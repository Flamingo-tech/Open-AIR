# ESPHome Open Air Valve

Visit https://esphome.io/ for instructions on how to deploy this firmware.

More documentation might come available in future updates. Make sure to copy `example.secrets.yaml` to `secrets.yaml` and fill it with your own wifi credentials.

Change the "X" in `open-air-valve.yaml` with a number or a letter. This will help you identify the Open AIR Valves.

## Hall Sensor Homing

Since version V1.4.0 of the Open AIR Valve , the Omron Switch is changed for a more reliable mechanism: A hall sensor.
The signal of the sensor is inverted! so a small change to your YAML file is needed if you upgrade.

```yaml
binary_sensor:
  - platform: gpio
    id: valve_homing_switch
    pin:
      number: GPIO35
      inverted: true #Change this to "false" if you hava a homing switch from pre V1.4.0 Open AIR Valve.
    name: "Valve Closed Switch"
```

## Sensors

The following sensors are supported right away, either via ESPHome or via a custom implementation.

### New Sensors:
All Valves are now shipped with these sensors:
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

If you have a SHT-20 Sensor add the following code at the bottom of `open-air-valve.yaml` 

```yaml
external_components:
  - source: github://dmaasland/esphome@sht2x
    components: [ sht2x ]
```

```yaml
  - platform: sht2x
    i2c_id: i2c_sensor_1
    temperature:
      name: "Open AIR Valve x Temperature"
      id: air_temperature
      accuracy_decimals: 2
    humidity:
      name: "Open AIR Valve x Humidity"
      id: air_humidity
      accuracy_decimals: 2
    update_interval: 30s
```
Thanks @dmaasland : https://github.com/dmaasland/esphome/tree/sht2x/esphome/components/sht2x

### Sensor Support: SCD-4X

More info about this sensor and ESPhome : https://esphome.io/components/sensor/scd4x.html

If you want to add a SCD-40 moisture & Temperature sensor & Co2 sensor to the Open AIR Mini, add the following code at the bottom of the `open-air-valve.yaml` file.

```yaml
sensor:
  - platform: scd4x
    i2c_id: i2c_sensor_1 
      name: "Open AIR Valve x CO2"
      id: air_Co2
      accuracy_decimals: 0
    temperature:
      name: " Open AIR Valve x Temperature"
      id: air_temperature
      accuracy_decimals: 2
    humidity:
      name: " Open AIR Valve x Humidity"
      id: air_humidity
      accuracy_decimals: 2
    update_interval: 30s
    measurement_mode: periodic
```

### Sensor Support: SGP-41

More info about this sensor and ESPhome : https://esphome.io/components/sensor/sgp4x.html & https://esphome.io/components/sensor/scd4x.html

If you want to add a combination sensor SCD-40 moisture & Temperature sensor & Co2 sensor & SGP-41 VOC & NOx to the Open AIR Mini, add the following code at the bottom of the `open-air-valve.yaml` file.

```yaml
sensor:
  - platform: sgp4x
    i2c_id: i2c_sensor_1 
    voc:
      name: "VOC Index Valve x"
      id: air_VOC
    nox:
      name: "NOx Index Valve x"
      id: air_NOx
    compensation:
      temperature_source: air_temperature #Make sure to match these if you change ID's.
      humidity_source: air_humidity       #Make sure to match these if you change ID's.
    update_interval: 30s
```

### Sensor Support: SCD-40 & SGP-41 Combination Sensor

More info about this sensor and ESPhome : https://esphome.io/components/sensor/sgp4x.html

If you want to add a SGP-41 VOC & NOx to the Open AIR Mini, add the following code at the bottom of the `open-air-valve.yaml` file.

```yaml
sensor:
  - platform: scd4x
    i2c_id: i2c_sensor_1 
      name: "Open AIR Mini Sensor Valve x CO2"
      id: air_Co2
      accuracy_decimals: 0
    temperature:
      name: "Open AIR Mini Sensor Valve x Temperature"
      id: air_temperature
      accuracy_decimals: 2
    humidity:
      name: "Open AIR Mini Sensor Valve x Humidity"
      id: air_humidity
      accuracy_decimals: 2
    update_interval: 30s
    measurement_mode: periodic

  - platform: sgp4x
    i2c_id: i2c_sensor_1 
    voc:
      name: "Valve x VOC Index "
      id: air_VOC
    nox:
      name: "Valve x NOx Index "
      id: air_NOx
    compensation:
      temperature_source: air_temperature #Make sure to match these if you change ID's.
      humidity_source: air_humidity       #Make sure to match these if you change ID's.
    update_interval: 30s
```


## Old:

### Sensor Support: SHT-31

More info about this sensor and ESPhome : https://esphome.io/components/sensor/sht3xd.html

If you want to add a SHT-31 moisture & Temperature sensor to the Open AIR Mini, add the following code at the bottom of the `open-air-valve.yaml` file.

```yaml
sensor:
  - platform: sht3xd
    i2c_id: i2c_sensor_1
    temperature:
      name: "Temperature Open AIR Valve x"
      id: air_temperature
    humidity:
      name: "Humidity Open AIR Valve x"
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
      name: "CO2 Open AIR Valve x"
    update_interval: 60s
```



### Using the Combination Sensor with Senseair S8 & SHT-31 on the same board

If you want to use this specific combination sensor, add the following to the bottom of the `open-air-valve.yaml` file.

```yaml
sensor:
  - platform: sht3xd
    i2c_id: i2c_sensor_1
    temperature:
      name: "Temperature Open AIR Valve x"
      id: air_temperature
    humidity:
      name: "Humidity Open AIR Valve x"
      id: air_humidity
    address: 0x44
    update_interval: 60s
  - platform: senseair
    uart_id: uart_sensor_1
    co2:
      name: "CO2 Open AIR Valve x"
      id: air_co2
    update_interval: 60s
```

## Disconnected Mode

When Home Assistant cannot be reached, either because of a lack of WiFi connection or the Home Assistant server being unavailable, a `disconnected mode` has been added to provide basic functionality to the Open AIR Valve unit. This mode will allow the unit to continue standalone. When losing connection to Home Assistant or to your WI-FI network the valve will open automatically. 
