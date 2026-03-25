# Embedded-C-Microcontrollers
# Embedded C: Microcontroller Hardware Interfacing

## 📌 About the Project
This repository contains bare-metal embedded C code developed for Microchip microcontrollers (dsPIC33/PIC24 architecture). It demonstrates direct hardware manipulation, bypassing high-level operating systems to directly configure CPU registers, handle hardware interrupts, and manage precise timing mechanisms.

Proficiency in bare-metal programming is a critical skill for Automotive Software Engineering, real-time control systems, and low-level platform architecture.

## ⚙️ Core Features
* **Hardware Timers:** Configuration of 16-bit and 32-bit timers (`Timer1`, `Timer2/3`), calculating prescalers (`TCKPS`), and setting exact period registers (`PR1`, `PR2`, `PR3`) for precise task scheduling (e.g., 350us delays).
* **Interrupt Service Routines (ISR):** Implementation of non-blocking execution using hardware interrupts for both timers (`_T1Interrupt`, `_T3Interrupt`) and external sensor triggers (`_INT0Interrupt`).
* **GPIO Manipulation:** Pin-level configuration (`TRISB`) and bitwise operations to read external sensor data and drive output signals (e.g., LED toggling via `_RB15`).

## 🛠️ Tech Stack & Concepts
* **Language:** Embedded C (`xc16` compiler environment)
* **Hardware:** Microchip PIC / dsPIC Architectures
* **Concepts:** Bare-metal Programming, Interrupt Handling (ISR), Hardware Timers, General-Purpose Input/Output (GPIO), Register-level Configuration.

## 📁 Repository Structure
* `l3.c` - Implementation of external interrupt handling (INT0) for an obstacle sensor, triggering on specific signal edges.
* `l4.c` - Configuration and handling of hardware timers in both 16-bit and 32-bit modes for precise time-keeping and interrupt generation.
