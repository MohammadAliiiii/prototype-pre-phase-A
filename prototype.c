#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 7, 6, 5, 4, 3);

// Sensor & Actuator Pins
const int tempPin = A0;       // Temperature sensor
const int lightPin = A1;      // Light sensor (proxy for solar irradiance)
const int orientPin = A2;     // Orientation sensor (tilt)
const int solarPin = A3;      // Solar panel voltage
const int batteryPin = A4;    // Battery voltage
const int radiationPin = A5;  // Radiation proxy sensor

const int buzzerPin = 8;      // Alert buzzer
const int buttonPin = 2;      // Mode selection button
const int modeLed = 9;        // Mode indication LED
const int dangerLed = 10;     // Danger alert LED
const int commLed = 11;       // Communication status LED

int mode = 0;
unsigned long lastPress = 0;
unsigned long startTime;

// Thresholds for alerts
const int TEMP_HIGH_THRESHOLD = 50;        // Celsius
const float BATTERY_LOW_THRESHOLD = 3.3;  // Volts
const int RADIATION_HIGH_THRESHOLD = 300; // Arbitrary units

// Read analog sensor and convert to voltage (0-5V scale)
float readVoltage(int pin) {
  return analogRead(pin) * (5.0 / 1023.0);
}

// Debounce button press and cycle mode
void handleButton() {
  if (digitalRead(buttonPin) == LOW && (millis() - lastPress) > 300) {
    mode = (mode + 1) % 6;
    lastPress = millis();
    lcd.clear();
  }
}

// Display a warning alert (buzzer + LED)
void alertOn(bool on) {
  digitalWrite(dangerLed, on ? HIGH : LOW);
  if (on) {
    tone(buzzerPin, 1000);
  } else {
    noTone(buzzerPin);
  }
}

// Show system uptime (hh:mm)
void displayUptime() {
  unsigned long uptimeSec = (millis() - startTime) / 1000;
  lcd.print("Uptime: ");
  lcd.print(uptimeSec / 3600);
  lcd.print("h ");
  lcd.print((uptimeSec % 3600) / 60);
  lcd.print("m");
}

void setup() {
  lcd.begin(16, 2);

  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(modeLed, OUTPUT);
  pinMode(dangerLed, OUTPUT);
  pinMode(commLed, OUTPUT);

  lcd.print("Booting CubeSat");
  delay(2000);
  lcd.clear();

  startTime = millis();
}

void loop() {
  // Read raw sensor data
  int tempRaw = analogRead(tempPin);
  int lightRaw = analogRead(lightPin);
  int orientRaw = analogRead(orientPin);
  int radiationRaw = analogRead(radiationPin);

  // Convert sensor readings
  int tempC = map(tempRaw, 0, 1023, -40, 125);
  int lightPercent = map(lightRaw, 0, 1023, 0, 100);
  int tiltDeg = map(orientRaw, 0, 1023, -90, 90);
  int radiationLevel = map(radiationRaw, 0, 1023, 0, 500);

  float solarV = readVoltage(solarPin);
  float batteryV = readVoltage(batteryPin);

  // Detect danger conditions
  bool danger = false;
  if (tempC > TEMP_HIGH_THRESHOLD) danger = true;
  if (batteryV < BATTERY_LOW_THRESHOLD) danger = true;
  if (radiationLevel > RADIATION_HIGH_THRESHOLD) danger = true;

  alertOn(danger);

  // Communication status simulation (LED blinking faster if strong)
  int commSignal = lightPercent; // Using light as proxy for comm strength
  if (commSignal > 70) {
    digitalWrite(commLed, (millis() % 500 < 250) ? HIGH : LOW);
  } else {
    digitalWrite(commLed, (millis() % 1000 < 500) ? HIGH : LOW);
  }

  // Mode LED blinks every 500 ms
  digitalWrite(modeLed, (millis() / 500) % 2);

  // Handle button press to change modes
  handleButton();

  lcd.setCursor(0, 0);
  lcd.setCursor(0, 1);

  switch (mode) {
    case 0: {
      // Temperature & Light
      lcd.print("Temp:");
      lcd.print(tempC);
      lcd.print("C ");

      lcd.setCursor(0, 1);
      lcd.print("Light:");
      lcd.print(lightPercent);
      lcd.print("%   ");
      break;
    }

    case 1: {
      // Orientation (tilt)
      lcd.print("Orientation:");
      lcd.setCursor(0, 1);
      lcd.print("Tilt:");
      lcd.print(tiltDeg);
      lcd.print(" deg ");
      break;
    }

    case 2: {
      // Power: Solar vs Battery voltage
      lcd.print("Solar:");
      lcd.print(solarV, 2);
      lcd.print("V ");

      lcd.setCursor(0, 1);
      lcd.print("Batt:");
      lcd.print(batteryV, 2);
      lcd.print("V ");
      break;
    }

    case 3: {
      // Radiation & Comm signal proxy
      lcd.print("Rad Level:");
      lcd.print(radiationLevel);

      lcd.setCursor(0, 1);
      lcd.print("Comm Sig:");
      lcd.print(commSignal);
      lcd.print("% ");
      break;
    }

    case 4: {
      // System uptime display
      displayUptime();
      break;
    }

    case 5: {
      // Idle status screen
      lcd.print("All Systems OK");
      lcd.setCursor(0, 1);
      lcd.print(">> CubeSat << ");
      break;
    }
  }

  delay(3000);
}
