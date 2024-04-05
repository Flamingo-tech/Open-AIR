# ESPHome Open Air Valve

Visit https://esphome.io/ for instructions on how to deploy this firmware.

More documentation might come available in future updates. Make sure to copy `example.secrets.yaml` to `secrets.yaml` and fill it with your own wifi credentials.

Change the "X" in `open-air-valve.yaml` with a number or a letter. This will help you identify the Open AIR Valves.

## Sensors

The following sensors are supported right away, either via ESPHome or via a custom implementation.

1. [SHT-31](#sensor-support-sht-31)
1. [Senseair S8](#sensor-support-senseair-s8)
1. [SHT-20](#sensor-support-sht-20)
1. [SHT-31 & Senseair S8 Combination Sensor](#Using-the-Combination-Sensor-with-Senseair-S8-&-SHT-31-on-the-same-board)



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


### SHT-20 Sensor

If you have a SHT-20 Sensor add the following code at the bottom of `open-air-valve.yaml` 

```yaml
sensor:
  - platform: custom
    lambda: |-
      auto sht20 = new SHT20();
      App.register_component(sht20);
      return {sht20->temperature_sensor, sht20->humidity_sensor, sht20->vpd_sensor, sht20->dew_point_sensor};
    sensors:
      - name: "Temperature Open AIR Valve x"
        id: air_temperature
        unit_of_measurement: °C
        accuracy_decimals: 2
      - name: "Humidity Open AIR Valve x"
        id: air_humidity
        unit_of_measurement: "%"
        accuracy_decimals: 2
      - name: "Open AIR Valve x Vapour-pressure deficit"
        id: air_vapor_pressure_deficit
        unit_of_measurement: "kPa"
        accuracy_decimals: 2
      - name: "Open AIR Valve x Dew point"
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

Place the SHT20.H file in the same directory as the `open-air-valve.yaml`.

@[wre](https://github.com/wrenoud) Thanks for your support on this sensor implementation

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
