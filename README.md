<a>
    <img src="openrad_logo.png" alt="Openrad logo" align="left" height="60" />
</a>

# OpenRad
Introducing OpenRad, a simple radiation monitoring solution powered by the SBM-20 GM tube and TTGO ESP32 microcontroller. this project offers a user-friendly approach to tracking and measuring radiation levels.

<a href="https://www.pcbway.com/project/shareproject/OpenRad_A_Geiger_Counter_using_SBM_20_and_ESP32_7f1d54d7.html"><img src="Get on PCBWay.png" alt="PCB from PCBWay" /></a>

# Table of Contents
- [Demo](#demo)
- [Install](#install)
- [Folder Structure](#folder-structure)
- [FAQS](#faqs)
- [License](#license)

# Demo
### Device UI
![Images](demo_gif.gif)
### Youtube Demo
[![Demo Video](https://img.youtube.com/vi/kaBPnBUhCXA/0.jpg)](https://www.youtube.com/watch?v=kaBPnBUhCXA)
[![Demo Video](https://img.youtube.com/vi/ACgCJScDpeg/0.jpg)](https://www.youtube.com/watch?v=ACgCJScDpeg)

# Install
1. Install [VSCode](https://code.visualstudio.com/).
2. Install [PlatformIO](https://platformio.org/).
3. Clone this repository 
```bash
git clone https://github.com/omarkhorshid/OpenRad.git
```
4. (optional) Install [Squareline Studio](https://squareline.io/).
5. (optional) For Squareline, Change the project settings save paths to match your project directory.
6. In PlatformIO extension: Platform > Upload the Filesystem Image.
7. In PlatformIO extension: General > Upload the code to the TTGO board.

# Dependencies
- [lvgl v8.3.11](https://github.com/lvgl/lvgl/tree/release/v8.3)
- [TFT_eSPI v2.4.61](https://github.com/Bodmer/TFT_eSPI)
- [AsyncTCP-esphome v1.2.2](https://github.com/esphome/AsyncTCP.git)
- [ESPAsyncWebServer-esphome v2.1.0](https://github.com/esphome/ESPAsyncWebServer.git)
- [PubSubClient v2.8](https://github.com/knolleary/pubsubclient.git)
- [ArduinoJson v7.0.4](https://github.com/bblanchon/ArduinoJson.git)

# Folder Structure
### Software/Firmware/src
- `hardware.cpp/h` : Contains hardware init and functions. 
- `settings.cpp/h` : Contains the settings.
- `geiger.cpp/h` : Contains geiger calculations.
- `gui.cpp/h` : Contains LVGL functions.
- `connectivity.cpp/h` : Contains all the connectivity functions.

### Software/Firmware/lib/ui/src
- `ui_events.c/h` : Contains the UI events.

### Software/Firmware/data
- `index.html` : Contains the web interface.
- `chart.js` : Chart.js Library file.

# Schematics
![Schematics](./Hardware/Schematics.png)
[View project schematics](./Hardware/Schematics.pdf)

# FAQs
### How do I Navigate the UI in OpenRad?
Using the three buttons, up down and enter. ...

### How do I change the measuring window?
After uploading the code to the ESP, open the settings cogwheel, and change the settings you want.

### How do I turn OpenRad off?
- For **Sleep mode**: Navigate to the power button and click it.
- For **Deep Sleep mode**: Hold the button untill this message pops up, then release it before it disappears.

### What types of connectivity does OpenRad have?
OpenRad has WiFi and MQTT connectivity to be able to remotely monitor the radiation levels from the Web interface.

### How do I connect to OpenRad?
To connect to OpenRad and access the web interface:

If not connected to a Wifi network:
1. Enable Wifi from the on device settings
2. Enable "Wi-Fi Access Point"
3. Connect to the device's AP using the password on screen
4. Navigate to "http://192.168.4.1" or use the "Manage Router" option on your phone

If Connected:
- From a device on the same network navigate to the IP address showing on the device screen in the Connectivity settings

### What are the Measurement Settings?
1. **Window Size:** Number of samples used to calculate the average radiation intensity.

- **Bigger** values help the device give a more stable reading and theoretically increse its precision, but it will react slowler to changes.
- **Smaller** values help the device react faster to changes, but the readings might fluctuate more and theoretically decrease the precision.

2. **Sampling Period**: This is how often the device takes a reading (e.g., every N milliseconds).
- **Bigger** values make the device take readings less frequently, reducing energy consumption during sleep, but the device will react slower to changes.
- **Smaller** values make the device take readings more often, making it quicker to detect changes, but the readings may be less precise and the device consumes more power during sleep (If sleep sampling is enabled).
# License
OpenRad is [BSD-3 Licensed](license.txt '3-Clause BSD License')
