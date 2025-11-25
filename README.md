# Simulink-to-STM32 Embedded DSP Filters

This project implements real-time digital signal filtering on an STM32 microcontroller using the filters originally designed and simulated in MATLAB/Simulink.

The STM32G474RE receives an analog signal through the ADC, processes the signal through one of five digital filters, and outputs the filtered signal through the DAC. A signal generator and oscilloscope were used to validate real-time embedded DSP performance.

---

## 🎯 Project Objectives

- Design and validate five digital filters in MATLAB/Simulink:
  - Low-Pass Filter (LPF)
  - High-Pass Filter (HPF)
  - All-Pass Filter (APF)
  - Band-Pass Filter (BPF)
  - Band-Stop / Notch Filter (BSF)
- Deploy the filters to STM32 using C firmware
- Synchronize ADC sampling using Timer 1 at 10 kHz
- Output filtered signals for oscilloscope validation

---

## 🧩 System Architecture

### Embedded Flow
1. **ADC1** (PA0) samples analog input signal.
2. Sample is processed using the selected DSP filter C function.
3. **DAC1** (PA4) outputs filtered analog result.
4. **TIM1** provides a 10 kHz sampling trigger via TRGO.

---

## 📂 Repository Structure

📁 stm/ → STM32CubeIDE project

📁 matlab/ → Filter modeling and simulation (MATLAB/Simulink)

📄 lab3_2025020338-1.pdf → Final written report




---

## 🛠 STM32 Peripherals

| Peripheral | Pin | Function |
|-----------|-----|----------|
| ADC1      | PA0 | Analog input |
| DAC1      | PA4 | Filtered signal output |
| TIM1      | —   | 10 kHz sampling trigger |

All configuration screenshots are included in the report.

---

## 🚀 How to Build

1. Open the project in STM32CubeIDE
2. Connect an external signal generator to PA0
3. Connect oscilloscope to PA0 (input) & PA4 (output)
4. Flash firmware to STM32G474RE board
5. Press reset → Real-time filter runs automatically

---

## 📌 Filter Selection

Update this variable inside `main.c`:

```
volatile filter_t current_filter = FILTER_BPF;
FILTER_LPF
FILTER_HPF
FILTER_APF
FILTER_BPF
FILTER_BSF
---

Developed by: Raymundo
Tecnológico de Monterrey — Robotics and Digital Systems Engineering
2025
© 2025. All rights reserved.
