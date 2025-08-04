const int sensorPin = A0;
const int ledPin = 13;
const int buzzerPin = 9; 

int sensorValue;

// Порог обнаружения газа (настраивать тут)
int threshold = 210; //<200 в покое, бутан с зажигалки - 500-700+, пердеж 220 вблизи

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT); 
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Gas detected!");
    tone(buzzerPin, 1000, 800);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin); 
  }
  delay(1000);
}


