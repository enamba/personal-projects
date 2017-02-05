/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/


int analogPin = 3;     // potentiometer wiper (middle terminal) connected to analog pin 3
int dPinRele = 3;
int val = 0;           // variable to store the value read
int c1 = 0 ;
int c2 = 0;
int limitUp = 600;
int limitDown = 450;
int subCount = 100;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(dPinRele, OUTPUT);
  digitalWrite(dPinRele, HIGH); 
  Serial.begin(9600);          //  setup serial
  
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);                       // wait for a second
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);                       // wait for a second
  delay(500); 
  val = analogRead(analogPin);    // read the input pin
  if (val > limitUp) {
    c1++;
  } else {
    c1 = 0;
  }

  if (c1 > subCount) {
    digitalWrite(dPinRele, LOW);
  }


  if (val < limitDown) {
    c2++;
  } else {
    c2 = 0;
  }

  if (c2 > subCount) {
    digitalWrite(dPinRele, HIGH);
  }
    
  Serial.print(val);             // debug value
  Serial.print(" - c1:");
  Serial.print (c1);
  Serial.print(" - c2:");
  Serial.println (c2);
}


//700 > seco

// 400 < humido

