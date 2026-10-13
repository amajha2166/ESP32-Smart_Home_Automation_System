# ESP32-Smart_Home_Automation_System
It is a Home Automation System used, using ESP32 WiFi Module, 2 Bulbs and Relay module working as bridge between microcontroller and AC Powered Bulbs. It is connected with a Mobile App made on MIT App Inventor, with basic interface having ON and OFF buttons to control both Bulbs.

# ESP32 Smart Home Automation

A Wi-Fi-based home automation project using an ESP32, a two-channel relay module, and an Android application developed with MIT App Inventor.

## Features

- Independent ON/OFF control of two bulbs
- Wireless control over Wi-Fi
- HTTP-based communication between the Android app and ESP32
- ESP32-hosted web interface for testing
- Expandable architecture for additional appliances

## Hardware

- ESP32 development board
- Two-channel relay module compatible with the ESP32
- Two bulbs and appropriate holders
- Breadboard and jumper wires for low-voltage prototyping
- USB cable and suitable power supply
- Android smartphone
- Bulb Holders
- Copper wires for bulbs

## Software

- Arduino IDE
- ESP32 Arduino Core
- MIT App Inventor
- HTTP server using the ESP32 `WebServer` library

## System Architecture

Android App → Wi-Fi → ESP32 HTTP Server → Relay Module → Bulbs

## Relay Pin Mapping

| Signal | ESP32 GPIO |
|---|---|
| Relay IN1 | GPIO 26 (provisional) |
| Relay IN2 | GPIO 27 (provisional) |

Verify these pins against the actual circuit before use.

## HTTP Commands

| Action | Endpoint |
|---|---|
| Bulb 1 ON | `/bulb1/on` |
| Bulb 1 OFF | `/bulb1/off` |
| Bulb 2 ON | `/bulb2/on` |
| Bulb 2 OFF | `/bulb2/off` |

## Setup

1. Install Arduino IDE and the ESP32 board package.
2. Open the firmware in `firmware/`.
3. Verify relay pins, logic polarity, and power requirements.
4. Upload the firmware to the ESP32.
5. Connect the phone to the ESP32 access point or the configured local Wi-Fi network.
6. Import the MIT App Inventor `.aia` file or recreate the app.
7. Test each relay channel independently before connecting mains-powered loads.

## Safety

Mains-powered loads must be switched using a properly rated, enclosed relay assembly. Keep mains wiring isolated from low-voltage electronics and have a qualified electrician verify the installation.

## Testing Status

Update this section with verified results and known limitations.

## License

See `LICENSE`.
