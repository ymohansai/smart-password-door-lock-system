# smart-password-door-lock-system

## Live Simulation
https://wokwi.com/projects/467549189554511873

## Description

This project is an Arduino-based Smart Password Door Lock System. A user enters a 4-digit password using a 4x4 keypad. If the entered password is correct, the servo motor unlocks the door and an LED turns ON. If the password is incorrect, the LCD displays an error message and the door remains locked.

## Components Used

- Arduino Uno
- 4x4 Keypad
- Servo Motor
- 16x2 LCD with I2C Module
- LED
- Jumper Wires

## Working

- The LCD prompts the user to enter a password.
- The user enters a 4-digit password using the keypad.
- If the password is correct:
  - The servo motor rotates to unlock the door.
  - The LCD displays **DOOR UNLOCKED**.
  - The LED turns ON.
- If the password is incorrect:
  - The LCD displays **WRONG PASSWORD**.
  - The door remains locked.

## Software Used

- Wokwi Simulator
- Arduino IDE

## Technologies Used

- Embedded C
- Arduino Programming
- I2C Communication
- Servo Motor Control
- Keypad Interfacing

## Author

**Mohan Sai Yalavarthi**
