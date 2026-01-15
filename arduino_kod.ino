// -------- PIN TANIMLARI --------
#define trig1 8
#define echo1 9

#define trig2 6
#define echo2 7

#define vibrationPin 3

// -------- MESAFE SINIRLARI (cm) --------
#define depthLimit 50
#define obstacleLimit 30

// -------- MESAFE ÖLÇÜM FONKSİYONU --------
long measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return -1;   // ölçüm yok

  long distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);

  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  pinMode(vibrationPin, OUTPUT);
  digitalWrite(vibrationPin, LOW);

  Serial.begin(9600);
}

void loop() {
  long depthDistance = measureDistance(trig1, echo1);
  long obstacleDistance = measureDistance(trig2, echo2);

  Serial.print("Derinlik: ");
  Serial.print(depthDistance);
  Serial.print(" cm | Engel: ");
  Serial.print(obstacleDistance);
  Serial.println(" cm");

  // ---- DERİNLİK (UZUN TİTREŞİM) ----
  if (depthDistance > depthLimit && depthDistance < 300) {
    digitalWrite(vibrationPin, HIGH);
    delay(1000);
    digitalWrite(vibrationPin, LOW);
  }

  // ---- ENGEL (KISA TİTREŞİM) ----
  else if (obstacleDistance > 0 && obstacleDistance < obstacleLimit) {
    digitalWrite(vibrationPin, HIGH);
    delay(300);
    digitalWrite(vibrationPin, LOW);
  }

  delay(200);
}
