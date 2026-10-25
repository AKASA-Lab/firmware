// Aeroponic misting controller — 8 pumps, sequential
// Relay board is active-LOW: LOW = pump ON, HIGH = pump OFF

const int PUMPS[8] = {13, 4, 18, 19, 21, 22, 23, 27};

const unsigned long MIST_MS = 15000;    // 15 s spray per bucket
const unsigned long GAP_MS  = 22500;    // 22.5 s gap -> 5 min full cycle

unsigned long cycle = 0;

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 8; i++) {
    pinMode(PUMPS[i], OUTPUT);
    digitalWrite(PUMPS[i], HIGH);      // every pump off before anything else
  }

  delay(5000);                         // settle before the first spray
  Serial.println("Misting controller started");
}

void loop() {
  cycle++;
  Serial.print("=== cycle ");
  Serial.print(cycle);
  Serial.print(" at ");
  Serial.print(millis() / 1000);
  Serial.println(" s");

  for (int i = 0; i < 8; i++) {
    digitalWrite(PUMPS[i], LOW);
    Serial.print("  bucket ");
    Serial.print(i + 1);
    Serial.println(" spraying");
    delay(MIST_MS);

    digitalWrite(PUMPS[i], HIGH);
    delay(GAP_MS);
  }
}
