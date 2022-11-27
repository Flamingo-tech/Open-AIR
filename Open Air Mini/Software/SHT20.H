
Skip to content
Pull requests
Issues
Codespaces
Marketplace
Explore
@Flamingo-tech
thomasvnl /
esphome-open-air-valve
Public

Code
Issues
Pull requests
Actions
Projects
Wiki
Security

    Insights

esphome-open-air-valve/SHT20.H
The Flamingo added support for SHT-20
Latest commit 04e7fca Nov 18, 2022
History
0 contributors
executable file 39 lines (32 sloc) 1.22 KB
#include "esphome.h"
#include "uFire_SHT20.h"

class SHT20 : public PollingComponent {
 public:
  uFire_SHT20 sht20;
  Sensor *temperature_sensor = new Sensor();
  Sensor *humidity_sensor = new Sensor();
  Sensor *vpd_sensor = new Sensor();
  Sensor *dew_point_sensor = new Sensor();

  // To prevent self-heating, the datasheet warns to do
  // maximum two measurements per second at 12-bit accuracy.
  // But according to the datasheet
  // (https://www.mouser.com/datasheet/2/682/Sensirion_Humidity_Sensors_SHT20_Datasheet-1274196.pdf)
  // response time of the humidity sensor is optimally 8s, and for
  // the temperature 5s-30s. So lets poll at 4s, or half the response time.
  SHT20() : PollingComponent(30000) { }

  void setup() override {
    if(!sht20.begin()) {
      ESP_LOGE("SHT20", "Sensor is not connected");
    }
  }

  void update() override {
    float temperature = sht20.temperature();
    temperature_sensor->publish_state(temperature);

    float humidity = sht20.humidity();
    humidity_sensor->publish_state(humidity);

    float vpd = sht20.vpd();
    vpd_sensor->publish_state(vpd);

    float dew_point = sht20.dew_point();
    dew_point_sensor->publish_state(dew_point);
  }
};
Footer
© 2022 GitHub, Inc.
Footer navigation

    Terms
    Privacy
    Security
    Status
    Docs
    Contact GitHub
    Pricing
    API
    Training
    Blog
    About

thomasvnl/esphome-open-air-valve: Firmware for the Open AIR Valve by The Flamingo
esphome-open-air-valve/SHT20.H at main · thomasvnl/esphome-open-air-valve
