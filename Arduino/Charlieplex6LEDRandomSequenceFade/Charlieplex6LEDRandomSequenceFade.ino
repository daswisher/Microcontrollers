const int LED_1 = 11;
const int LED_2 = 10;
const int LED_3 = 5;
int ledChoice = 0;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int delayValue = 1000;
//#import <random>
void setup(){
  randomSeed(analogRead(0));
}
void loop()
{
  /*
  pinMode(LED_1, OUTPUT); //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT); //row 2
  analogWrite(LED_2, brightness);    
  
    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;
  
    // reverse the direction of the fading at the ends of the fade: 
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ; 
    }     
    // wait for 30 milliseconds to see the dimming effect    
    delay(30); 
  pinMode(LED_3, INPUT); //row 3
  digitalWrite(LED_3, LOW);
  */
  
  
  
  pinMode(LED_1, OUTPUT); //row 1
analogWrite(LED_1, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30); 
pinMode(LED_2, OUTPUT); //row 2
digitalWrite(LED_2, LOW);
pinMode(LED_3, INPUT); //row 3
digitalWrite(LED_3, LOW);

  /*
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
  */
  
}
//turn on LED L1
void led1(){
  brightness = 0;
  pinMode(LED_1, OUTPUT); //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT); //row 2
  analogWrite(LED_2, brightness);    
  
    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;
  
    // reverse the direction of the fading at the ends of the fade: 
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ; 
    }     
    // wait for 30 milliseconds to see the dimming effect    
    delay(30); 
  pinMode(LED_3, INPUT); //row 3
  digitalWrite(LED_3, LOW);
}
void led2(){
  brightness = 0;

//turn on LED L2
pinMode(LED_1, OUTPUT); //row 1
analogWrite(LED_1, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30); 
pinMode(LED_2, OUTPUT); //row 2
digitalWrite(LED_2, LOW);
pinMode(LED_3, INPUT); //row 3
digitalWrite(LED_3, LOW);
}
void led3(){
    brightness = 0;

//turn on LED L3
pinMode(LED_1, INPUT); //row 1
digitalWrite(LED_1, LOW);
pinMode(LED_2, OUTPUT); //row 2
digitalWrite(LED_2, LOW);
pinMode(LED_3, OUTPUT); //row 3
analogWrite(LED_3, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30); 
}
void led4(){
    brightness = 0;

//turn on LED L4
pinMode(LED_1, INPUT); //row 1
digitalWrite(LED_1, LOW);
pinMode(LED_2, OUTPUT); //row 2
analogWrite(LED_2, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30); 
pinMode(LED_3, OUTPUT); //row 3
digitalWrite(LED_3, LOW);
}
void led5(){
    brightness = 0;

//turn on LED L5
pinMode(LED_1, OUTPUT); //row 1
digitalWrite(LED_1, LOW);
pinMode(LED_2, INPUT); //row 2
digitalWrite(LED_2, LOW);
pinMode(LED_3, OUTPUT); //row3
analogWrite(LED_3, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  for(int i = 0; i < delayValue; i++){
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30); 
  }
}
void led6(){
    brightness = 0;

//turn on LED L6
pinMode(LED_1, OUTPUT);
analogWrite(LED_1, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30); 
pinMode(LED_2, INPUT);
digitalWrite(LED_2, LOW);
pinMode(LED_3, OUTPUT);
digitalWrite(LED_3, LOW);
}

void randomLED(){
  ledChoice=random(1,7);
  //return ledChoice;
}
