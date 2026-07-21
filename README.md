# IoT Voice-Controlled Vehicle (Proof of Concept)

## Overview
This repository contains the architectural documentation and web-server logic for a multi-microcontroller, Wi-Fi-enabled robotic vehicle. The project served as a hardware proof-of-concept for multi-voltage power distribution, isolated motor control, and hybrid local/network voice processing. 

*Note: This project is currently archived. The core networking code and hardware schematics are preserved here for architectural reference, while the local Arduino motor-control logic was lost during a hardware migration.*

## Hardware Architecture
<img src="https://github.com/user-attachments/assets/0b96f1bb-be41-48ad-82c1-7c6091692d5e" width="500">


The system architecture is split into two physical domains to ensure stability and isolate the logic chips from the heavy inductive loads of the DC motors:
*   **Networking Brain:** An ESP8266 handles Wi-Fi connectivity and serves a custom HTML/JS asynchronous web interface.
*   **Actuation Brain:** An Arduino Uno (paired with an L293D motor shield) receives serial commands from the ESP8266 to drive the motors.
*   **Power Distribution:** A multi-voltage setup using buck converters supplies 5V to the Arduino/Motors and an isolated, clean 3.3V to the ESP8266.
*   **Safety Failsafe:** An HC-SR04 ultrasonic sensor acts as a hardware-level override to prevent collisions in the event of network latency.

## Repository Contents
*   `esp8266_web_server.ino`: The custom C++ asynchronous web server serving the HTML/JS remote and handling serial routing.
