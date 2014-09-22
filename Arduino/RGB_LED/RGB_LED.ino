int pinGreen = 5;
int pinBlue = 6;
int pinRed = 3;
void setup(){
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  pinMode(pinRed, OUTPUT);
  digitalWrite(pinGreen, LOW);
  digitalWrite(pinBlue, LOW);
  digitalWrite(pinRed, LOW);
}

void loop(){
  redTest();
  blueTest();
  greenTest();
}

void redTest(){
  digitalWrite(pinRed, HIGH);
  delay(1000);
  digitalWrite(pinRed, LOW);
}

void greenTest(){
  digitalWrite(pinGreen, HIGH);
  delay(1000);
  digitalWrite(pinGreen, LOW); 
}

void blueTest(){
  digitalWrite(pinBlue, HIGH);
  delay(1000);
  digitalWrite(pinBlue, LOW); 
}
