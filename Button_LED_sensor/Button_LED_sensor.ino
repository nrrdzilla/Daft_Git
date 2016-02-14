//Initialize pins
int led = 3;                  //initialize pin 3 (PWM-capable) as LED
int brightness=0;             //initial LED brightness level
int button = 12;              //initialize pin 12 as Push-Button
int val = 0;                  //val will be used to store the state of the input pin
int vdiv = 0;                 //vdiv will be used to store the resultant voltage from the LDR+8K2 voltage divider

void setup()  {
  pinMode(led, OUTPUT);       //tell the Arduino LED is an output
  pinMode(button, INPUT);     //tell the Arduino Push-Button is an input
  analogReference(DEFAULT);
}

void loop()  {
  val = digitalRead(button);
  vdiv = analogRead(A0);
  if (val == LOW) {
    brightness=map(1024-vdiv,0,1024,2,128);
    analogWrite(led, brightness);
  }
}
