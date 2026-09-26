# AI-Assisted Classroom Noise Level Monitor

## 1. Project Overview

The AI-Assisted Classroom Noise Level Monitor is an Arduino-based embedded system designed to monitor classroom noise levels. It uses a sound sensor to detect noise and displays the current noise category using three LEDs.

Artificial Intelligence (AI) is used during software development to assist with code generation, code review, test-case generation, and quality assurance.

## 2. Objectives

- Monitor classroom noise using a sound sensor.
- Classify noise into low, moderate, and high levels.
- Indicate noise levels using LEDs.
- Use AI to assist in identifying potential software defects.
- Track and resolve QA issues using GitHub Issues.

## 3. Hardware Requirements

- Arduino UNO
- KY-038 sound sensor or equivalent
- Green LED
- Yellow LED
- Red LED
- Current-limiting resistors
- Breadboard and jumper wires

## 4. Pin Configuration

| Component | Arduino Pin |
|
| Sound sensor AO | A0 |
| Green LED | D8 |
| Yellow LED | D9 |
| Red LED | D10 |

## 5. Working Principle

The sound sensor provides an analog signal corresponding to the detected sound intensity. The Arduino reads this signal and compares it against predefined thresholds.

- Low noise: Green LED
- Moderate noise: Yellow LED
- High noise: Red LED

The sensor reading and corresponding noise category are also displayed in the Serial Monitor.

## 6. AI Integration

AI is used as a software development and quality assurance assistant. It helps generate code, review the program, identify potential defects, and suggest test cases and improvements.

The Arduino executes conventional embedded-system logic; it does not run an AI model.

## 7. Quality Assurance

The project uses GitHub Issues to document software defects, testing observations, and proposed improvements. Issues are reviewed, fixed, and closed after verification.

Planned tests include:
- Noise threshold validation
- LED state verification
- Sensor reading validation
- LED flickering near threshold values
- Response time testing

## 8. Technologies Used

- Arduino UNO
- Embedded C++
- Git and GitHub
- GitHub Issues
- AI-assisted software testing

## 9. Future Improvements

- Add noise filtering to reduce LED flickering.
- Add a buzzer for excessive noise.
- Display readings on an LCD.
- Calibrate the system against a sound-level meter.
- Introduce automated testing for the classification logic.

## 10. Project Status

Version 1.0: Initial implementation of the classroom noise monitoring system.
