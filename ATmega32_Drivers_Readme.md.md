# ATmega32 Drivers

This repository contains a collection of drivers for the ATMega32 microcontroller. These drivers provide an abstraction layer to interact with various peripherals and functionalities of the ATMega32.

## Introduction
The ATMega32 Driver Library is designed to simplify the development process for projects based on the ATMega32 microcontroller. It provides a set of drivers that encapsulate the low-level details of interacting with various peripherals, allowing developers to focus on higher-level functionality.

## Supported Peripherals
The ATMega32 Drivers Repo currently supports the following peripherals:

#### In MCAL Layer :
-  GPIO (General Purpose Input/Output)
- Timer/Counter
- UART (Universal Asynchronous Receiver/Transmitter)
- SPI (Serial Peripheral Interface)
- I2C (Inter-Integrated Circuit)
- ADC (Analog-to-Digital Converter)
- WDT (Watchdog Timer)
- EEPROM
- EXInterruupt (External Interrupt)
#### In HAL Layer :
- LCD (Liquid Crystal Display)
- KeyPad
- Stepper Motor
- Servo Motor
- Ultrasonic
- Sensors
### In SERVICE Layer :
- Timer Services
- UART Services
- UART Stack

Each **peripheral driver** provides functions to initialize, configure, and utilize the corresponding peripheral.
