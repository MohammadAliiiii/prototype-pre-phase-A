<p align="center">
  <img src="https://raw.githubusercontent.com/MohammadAliiiii/prototype-pre-phase-A/main/PhoneSat.png" alt="PhoneSat Prototype" width="400" />
</p>


### Construction:

This PhoneSat is basically a **small satellite prototype built around a microcontroller and sensors**, using:

* **Microcontroller:** Arduino (UNO or similar) acts as the “brain” to read sensor data and control outputs.
* **Sensors:** Temperature, light, orientation (tilt), solar voltage, and battery voltage sensors connected to analog input pins (A0 to A5). These provide environmental data crucial for a satellite's health and function.
* **Display:** A 16x2 LCD module connected via digital pins to show telemetry and system status to users.
* **User Controls and Indicators:**

  * A **pushbutton** to switch modes or display screens.
  * **LEDs** (mode LED, danger LED, communication LED) to indicate system states visually.
  * **Buzzer** for audible alerts (warnings for high temperature, low battery, or radiation).
* **Power Inputs:** Simulated solar panel and battery voltage sensors help monitor power system status.
* **Wiring:** The components are wired to the Arduino’s digital and analog pins, with proper power and ground connections, allowing interaction between sensors, output devices, and the microcontroller.

---

### Working of Your PhoneSat

1. **Initialization (Setup):**
   When powered on, the microcontroller starts the program. The LCD displays a boot message like “Booting CubeSat” to confirm power-up and initialization. Pin modes are configured (inputs for sensors and buttons, outputs for LEDs and buzzer).

2. **Sensor Reading:**
   The Arduino continuously reads analog values from sensors:

   * Temperature sensor gives raw data converted to Celsius.
   * Light sensor acts as a proxy for solar irradiance or environment light.
   * Orientation sensor provides tilt angle.
   * Solar and battery pins measure voltage levels.
   * Radiation sensor monitors radiation levels (simulated or real).

3. **Mode Selection via Button:**
   Pressing the pushbutton cycles through different display modes on the LCD. Each mode shows specific data:

   * Mode 0: Temperature & Light
   * Mode 1: Orientation (Tilt)
   * Mode 2: Solar and Battery Voltages
   * Mode 3: Radiation and Communication Signal
   * Mode 4: System uptime
   * Mode 5: Idle or status screen

4. **Alerts and Status Indications:**

   * If any sensor reading crosses thresholds (high temp, low battery, or high radiation), the buzzer sounds and the danger LED lights up as an alert.
   * The communication LED blinks to simulate signal strength (based on light sensor).
   * The mode LED blinks regularly to indicate normal operation and mode status.

5. **Data Display:**
   The LCD updates every few seconds with sensor data or status messages relevant to the current mode. This provides real-time telemetry feedback.

6. **Power and Health Monitoring:**
   The system constantly checks solar input and battery voltage to simulate power management, essential for CubeSat missions to prevent power failures.

7. **Loop Cycle:**
   This process repeats continuously, reading sensors, updating outputs, managing user input, and alerting when necessary.

---

### Why This Matters for CubeSats

This PhoneSat mimics a **basic CubeSat mission’s key functions**:

* Monitoring critical environmental and power parameters.
* Managing alerts to protect satellite health.
* Allowing user/ground interaction via display and controls.
* Operating with simple, low-power hardware suitable for space constraints.

The overall design reflects how CubeSats must integrate sensors, power, communication, and user interfaces within limited size and complexity.

---

**Summary in simple terms:**
This PhoneSat is a small Arduino-based satellite prototype that reads environmental data (temp, light, orientation, power), shows it on an LCD, alerts on problems with buzzer and LEDs, and lets you switch screens with a button—just like a real CubeSat monitors itself and communicates status back to operators.

