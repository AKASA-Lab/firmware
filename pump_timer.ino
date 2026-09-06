// Aeroponic misting controller — single pump test
// Relay board is active-LOW: LOW = pump ON

#define PUMP_PIN 13

const unsigned long MIST_MS  = 5000;    // 5 seconds spray
const unsigned long PAUSE_MS = 235000;  // 235 s pause = 4 min cycle

unsigned long cycleCount = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, HIGH);   // ensure OFF at boot
  delay(3000);                    // settle before first spray
  Serial.println("Misting controller started");
}

void loop() {
  cycleCount++;

  digitalWrite(PUMP_PIN, LOW);
  Serial.print("Cycle ");
  Serial.print(cycleCount);
  Serial.print(" — spray ON at ");
  Serial.print(millis() / 1000);
  Serial.println(" s");
  delay(MIST_MS);

  digitalWrite(PUMP_PIN, HIGH);
  Serial.println("Spray OFF");
  delay(PAUSE_MS);
}