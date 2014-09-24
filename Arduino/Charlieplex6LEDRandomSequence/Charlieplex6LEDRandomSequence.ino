const int LED_1 = 13;
const int LED_2 = 12;
const int LED_3 = 11;
int ledChoice = 0;
//#import <random>
void setup(){
  randomSeed(analogRead(0));
}
void loop()
{
  randomLED();
  if(ledChoice==1){
    led1();
  }
  else if(ledChoice==2){
    led2();
  }
  else if(ledChoice==3){
    led3();
  }
  else if(ledChoice==4){
    led4();
  }
  else if(ledChoice==5){
    led5();
  }
  else{ //implicit ledChoice==6
    led6();
  }
  delay(1000);
}
//turn on LED L1
void led1(){
pinMode(LED_1, OUTPUT); //row 1
digitalWrite(LED_1, LOW);
pinMode(LED_2, OUTPUT); //row 2
digitalWrite(LED_2, HIGH);
pinMode(LED_3, INPUT); //row 3
digitalWrite(LED_3, LOW);
}
void led2(){

//turn on LED L2
pinMode(LED_1, OUTPUT); //row 1
digitalWrite(LED_1, HIGH);
pinMode(LED_2, OUTPUT); //row 2
digitalWrite(LED_2, LOW);
pinMode(LED_3, INPUT); //row 3
digitalWrite(LED_3, LOW);
}
void led3(){
//turn on LED L3
pinMode(LED_1, INPUT); //row 1
digitalWrite(LED_1, LOW);
pinMode(LED_2, OUTPUT); //row 2
digitalWrite(LED_2, LOW);
pinMode(LED_3, OUTPUT); //row 3
digitalWrite(LED_3, HIGH);
}
void led4(){
//turn on LED L4
pinMode(LED_1, INPUT); //row 1
digitalWrite(LED_1, LOW);
pinMode(LED_2, OUTPUT); //row 2
digitalWrite(LED_2, HIGH);
pinMode(LED_3, OUTPUT); //row 3
digitalWrite(LED_3, LOW);
}
void led5(){
//turn on LED L5
pinMode(LED_1, OUTPUT); //row 1
digitalWrite(LED_1, LOW);
pinMode(LED_2, INPUT); //row 2
digitalWrite(LED_2, LOW);
pinMode(LED_3, OUTPUT); //row3
digitalWrite(LED_3, HIGH);
}
void led6(){
//turn on LED L6
pinMode(LED_1, OUTPUT);
digitalWrite(LED_1, HIGH);
pinMode(LED_2, INPUT);
digitalWrite(LED_2, LOW);
pinMode(LED_3, OUTPUT);
digitalWrite(LED_3, LOW);
}

void randomLED(){
  ledChoice=random(1,7);
  //return ledChoice;
}
