<!-- README.md START -->

<h1 align="center">🛰️ PhoneSat: CubeSat Subsystem Prototype</h1>

<div align="center" style="margin: 20px 0;">
  <img 
    src="https://raw.githubusercontent.com/MohammadAliiiii/prototype-pre-phase-A/main/PhoneSat.png" 
    alt="PhoneSat Prototype" 
    style="border: 2px solid #444; border-radius: 10px; box-shadow: 0 4px 8px rgba(0,0,0,0.3); width: 80%; max-width: 600px;" 
  />
  <p style="font-style: italic; color: #555; margin-top: 10px;">
    Figure: PhoneSat - A functional subsystem model simulating real CubeSat operations
  </p>
</div>

---

## 📦 Construction

The **PhoneSat** is a functional micro-satellite emulator built using basic electronics and Arduino. It simulates core subsystems used in real CubeSats:

### 🚀 Core Components:
- **🔲 Microcontroller:** Arduino UNO (acts as the satellite's onboard computer)
- **📡 Sensors:**
  - Temperature (A0)
  - Light (A1)
  - Orientation/Tilt (A2)
  - Solar Panel Voltage (A3)
  - Battery Voltage / Radiation (A4)
- **🖥️ Display:**
  - 16x2 LCD (telemetry and system data)
- **🧠 User Interface:**
  - Pushbutton (mode change)
  - LEDs (Mode LED, Danger LED, Signal LED)
  - Buzzer (alerts for critical conditions)
- **🔋 Power Simulation:**
  - Simulated solar panel and battery inputs
- **🔌 Wiring:** Sensors and components are connected to Arduino’s I/O pins with proper voltage references and grounds.

---

## ⚙️ Working Principle

### 1. **Startup**
- Displays “Booting CubeSat” on LCD.
- Sets pin modes and initializes components.

### 2. **Sensor Monitoring**
- Reads analog sensor values continuously:
  - Temperature (°C)
  - Light intensity (%)
  - Tilt angle (degrees)
  - Solar/Battery voltage (V)
  - Simulated radiation levels

### 3. **User Interaction**
- Pushbutton cycles through **6 display modes**:
  1. **Temp & Light**
  2. **Tilt/Orientation**
  3. **Solar & Battery Voltage**
  4. **Radiation & Signal Strength**
  5. **Uptime Tracker**
  6. **System Status/Idle**

### 4. **Alerts & LED Indicators**
- **Danger LED**: Lights on high temp, radiation, or low battery
- **Signal LED**: Blinks based on light intensity (simulated comm signal)
- **Buzzer**: Sounds under critical conditions
- **Mode LED**: Indicates current mode (blinks or steady)

### 5. **LCD Display**
- Updates every few seconds to show real-time telemetry.
- Easy-to-read data with proper formatting and units.

---

## 🛰️ Why This Matters for CubeSat Design

This prototype mimics real CubeSat behavior:

- ✅ Power & thermal monitoring
- ✅ Environment sensing
- ✅ Alert & signal indicators
- ✅ Ground interaction (LCD/buttons)
- ✅ Low-cost, low-power hardware constraints

By simulating a satellite’s **Command and Data Handling (CDH)** and **Electrical Power System (EPS)** in a compact form, this model prepares for future expansions like communications, attitude control, or data logging.

---

## 📝 Summary (in Simple Words)

> This PhoneSat is like a mini space satellite you can hold in your hand. It checks things like temperature, sunlight, and how tilted it is. It shows that info on a screen, warns with lights and sound if something is wrong, and lets you switch views with a button—just like a real satellite that keeps itself safe and sends info back to Earth.

---

## 📁 Repository

- ✅ Code
- ✅ Schematics
- ✅ Images
- ✅ Documentation
> [GitHub Repository → prototype-pre-phase-A](https://github.com/MohammadAliiiii/prototype-pre-phase-A)

---

<!-- README.md END -->
