# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.1.0]

### Changed

* Changed to Valve component instead of blinds <-- Will break automations!!
* Moved old config in OLD YAML folder

### Added

* Added support for ESPHOME Version: 2025.9.1
* Added ESP-IDF instead of Arduino framework
* Added Version to Diagnostic tab in HA
* Added MCU Temperature in diagnostic tab in HA
* Added Uptime to diagnostic tab in HA
* Added WiFi IP in diagnostic tab in HA
* Added Re-home button, no need to reboot the whole controller
* Added Encryption support for API connection. KEY IS IN SECRETS.YAML Reprogram with your own generated key for proper security.
* Added substitutions for naming conventions for easier naming!


## [1.0.3]

* Added support for Hall Sensor Homing mechanism.

## [1.0.2]

### Added

* Added offline support. This will automatically open your Open AIR Valve when the connection to Home Assistant or your WI-FI network is lost

## [1.0.1]

### Changed

* Misnomer in the firmware for the fallback configuration hotspot that was using the old name instead of Open Air

## [1.0.0]

### Added

* Functionality to open and close the valve
* Look-up table to open/close valve based on effective amount of air flow instead of angle
* Boot valve position calibration using micro switch
