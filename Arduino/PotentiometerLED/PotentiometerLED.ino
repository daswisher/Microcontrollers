int sensorPin = 0;
int ledPin = 11;
int sensorValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  
}

void loop() {
  sensorValue = analogRead(sensorPin);    
  digitalWrite(ledPin, HIGH);  
  delay(sensorValue);          
  digitalWrite(ledPin, LOW);   
  delay(sensorValue);                  
}
