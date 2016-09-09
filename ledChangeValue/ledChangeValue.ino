/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 Pullupp-switch

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.

 This example code is in the public domain.
 */

// constants won't change. They're used here to
// set pin numbers:
const int addButtonPin = 2;     // the number of the pushbutton pin
const int deButtonPin = 3;
const int ledPin =  5;      // the number of the LED pin

boolean addButtonValue = true;   //Current add button value
boolean deButtonValue = true; //Current de button value
byte ledValue = 0; //Current led value

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(addButtonPin, INPUT_PULLUP);
  pinMode(deButtonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value, write the opposite value to ledPin:
  addButtonValue = digitalRead(addButtonPin); //Copy button value to the variable
  deButtonValue = digitalRead(deButtonPin); //Copy button value to the variable
  if (!addButtonValue) { //Check if the button is pressed
      ledValue += 15; //add pwm value
    }
  if (!deButtonValue) { //Check if the button is pressed
      ledValue -= 15; //de pwm value
    }
  analogWrite(ledPin, ledValue); //Write the values
delay(100); //Wait fo 20 mS
}
