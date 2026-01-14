// Pin tanımları
#define DEPTH_SIG 8      // Derinlik sensörü
#define OBSTACLE_SIG 7   // Engel sensörü
#define VIBRATION_PIN 3  // Titreşim motoru

void setup() {
  pinMode(DEPTH_SIG, INPUT);
  pinMode(OBSTACLE_SIG, INPUT);
  pinMode(VIBRATION_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int depthValue = digitalRead(DEPTH_SIG);
  int obstacleValue = digitalRead(OBSTACLE_SIG);

  Serial.print("Derinlik: ");
  Serial.print(depthValue);
  Serial.print(" | Engel: ");
  Serial.println(obstacleValue);

  // Derinlik algılandı → kısa titreşim
  if (depthValue == HIGH) {
    digitalWrite(VIBRATION_PIN, HIGH);
    delay(300);
    digitalWrite(VIBRATION_PIN, LOW);
  }

  // Engel algılandı → uzun titreşim
  if (obstacleValue == HIGH) {
    digitalWrite(VIBRATION_PIN, HIGH);
    delay(1000);
    digitalWrite(VIBRATION_PIN, LOW);
  }

  delay(200);
}
