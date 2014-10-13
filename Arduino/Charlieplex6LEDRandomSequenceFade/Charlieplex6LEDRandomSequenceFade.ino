//Ultrasonic code is used from Radioshack's Ultrasonic Sensor Support files
//http://www.radioshack.com/product/index.jsp?productId=23173056

#include "Arduino.h"
class Ultrasonic
{
	public:
		Ultrasonic(int pin);
        void DistanceMeasure(void);
		long microsecondsToCentimeters(void);
		long microsecondsToInches(void);
	private:
		int _pin;//pin number of Arduino that is connected with SIG pin of Ultrasonic Ranger.
        long duration;// the Pulse time received;
};
Ultrasonic::Ultrasonic(int pin)
{
	_pin = pin;
}
/*Begin the detection and get the pulse back signal*/
void Ultrasonic::DistanceMeasure(void)
{
    pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(_pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_pin,LOW);
	pinMode(_pin,INPUT);
	duration = pulseIn(_pin,HIGH);
}
/*The measured distance from the range 0 to 400 Centimeters*/
long Ultrasonic::microsecondsToCentimeters(void)
{
	return duration/29/2;	
}
/*The measured distance from the range 0 to 157 Inches*/
long Ultrasonic::microsecondsToInches(void)
{
	return duration/74/2;	
}

Ultrasonic ultrasonic(7);

//Set rails for the LEDs
const int LED_1 = 11;
const int LED_2 = 10;
const int LED_3 = 5;
const int LED_4 = 3;
int ledChoice = 0; //Variable used to store what LED is going to light up
class ledLight{
  private:
    int brightness;
    int fade;
    boolean lightUp;
    String row1;
    String row2;
    String row3;
    String row4;
  public:
    ledLight(){
      brightness=0;
      fade=1;
      lightUp=false; 
    }
    
    ledLight(String r1, String r2, String r3, String r4){
      brightness=0;
      fade=5;
      lightUp=false;
      row1=r1;
      row2=r2;
      row3=r3;
      row4=r4;
    }
    
    void lightLED(){
        setLED(row1, LED_1);
        setLED(row2, LED_2);
        setLED(row3, LED_3); 
        setLED(row4, LED_4);
    }

    void setLED(String state, const int LEDRow){
     if(state=="INPUT"){
      pinMode(LEDRow, INPUT);
      digitalWrite(LEDRow, LOW);
     } 
     else{  //Implicit that it will be high or low
       pinMode(LEDRow, OUTPUT);
       if(state=="LOW"){
         digitalWrite(LEDRow, LOW);
       }
       else{
         lightUp=true;
          while(lightUp!=false){
         brightness+=fade;
          if(brightness==255){
             fade=-fade; 
          }
          else if(brightness==0){
             fade=-fade;
            lightUp=false; 
          }
          analogWrite(LEDRow, brightness);
         delayMicroseconds(3000);
        }
        clearRails();
      }
     }
    }
};

ledLight Led1 = ledLight("LOW", "HIGH", "INPUT", "INPUT");
ledLight Led2 = ledLight("HIGH", "LOW", "INPUT", "INPUT");
ledLight Led3 = ledLight("INPUT", "LOW", "HIGH", "INPUT");
ledLight Led4 = ledLight("INPUT", "HIGH", "LOW", "INPUT");
ledLight Led5 = ledLight("INPUT", "INPUT", "LOW", "HIGH");
ledLight Led6 = ledLight("INPUT", "INPUT", "HIGH", "LOW");
ledLight Led7 = ledLight("LOW", "INPUT", "HIGH", "INPUT");
ledLight Led8 = ledLight("HIGH", "INPUT", "LOW", "INPUT");
ledLight Led9 = ledLight("INPUT", "LOW", "INPUT", "HIGH");
ledLight Led10 = ledLight("INPUT", "HIGH", "INPUT", "LOW");
ledLight Led11 = ledLight("LOW", "INPUT", "INPUT", "HIGH");
ledLight Led12 = ledLight("HIGH", "INPUT", "INPUT", "LOW");

void ledCycle(){ //This is a function used for testing to determine which LED is which
  Led1.lightLED(); 
  delay(1000);
  Led2.lightLED(); 
  delay(1000);
  Led3.lightLED(); 
  delay(1000);
  Led4.lightLED(); 
  delay(1000);
  Led5.lightLED(); 
  delay(1000);
  Led6.lightLED(); 
  delay(1000);
  Led7.lightLED(); 
  delay(1000);
  Led8.lightLED(); 
  delay(1000);
  Led9.lightLED(); 
  delay(1000);
  Led10.lightLED(); 
  delay(1000);
  Led11.lightLED(); 
  delay(1000);
  Led12.lightLED(); 
  delay(1000);
}

void clearRails(){ //Ensures that all power is pulled from lines before lighting a new LED
  pinMode(LED_1, INPUT);
  digitalWrite(LED_1, LOW);
      
  pinMode(LED_2, INPUT);
  digitalWrite(LED_2, LOW);
      
  pinMode(LED_3, INPUT);
  digitalWrite(LED_3, LOW);
  
  pinMode(LED_4, INPUT);
  digitalWrite(LED_4, LOW);
  
  delay(1);
}
void randomLED(){ //Randomly choose new LED to light
  ledChoice=random(1,13);
  //Serial.println(ledChoice);
  switch(ledChoice){
     case 1:
        Led1.lightLED();
        break; 
      case 2:
        Led2.lightLED();
        break; 
      case 3:
        Led3.lightLED();
        break; 
      case 4:
        Led4.lightLED();
        break; 
      case 5:
        Led5.lightLED();
        break; 
      case 6:
        Led6.lightLED();
        break; 
      case 7:
        Led7.lightLED();
        break; 
      case 8:
        Led8.lightLED();
        break;
      case 9:
        Led9.lightLED();
        break; 
      case 10:
        Led10.lightLED();
        break;
      case 11:
        Led11.lightLED();
        break; 
      case 12:
        Led12.lightLED();
        break; 
      default:
        clearRails();
  }
}

void setup(){
  //Serial.begin(9600);
}
void loop(){
  long RangeInInches;
  ultrasonic.DistanceMeasure();// get the current signal time;
  RangeInInches = ultrasonic.microsecondsToInches();//convert the time to inches;
  randomLED();
  delay(RangeInInches*100);
  //ledCycle();
}

