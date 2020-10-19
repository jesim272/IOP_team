/*
 * Created by Jesi Miranda-Santos
 * Last Updated: 10/18/2020
 * 
 */

const int butPin = 11;         // pin connected to button
const int s_pin = 10;           // Pin on SR latch
const int r_pin = 9;          // Pin on SR latch

#define DEBUG 0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);         // debug statement
  /* Output Pins */
  pinMode(s_pin, OUTPUT);
  pinMode(r_pin, OUTPUT);
  /* Input Pins */
  pinMode(butPin, INPUT);

  /* Turn Off system */
  digitalWrite(s_pin, LOW);
  digitalWrite(r_pin, HIGH);
}

void loop() {
  #if DEBUG
  int value = digitalRead(butPin);
  Serial.println(value);
  #endif
  
  if(!digitalRead(butPin)){
    #if DEBUG
    Serial.println("butPin is HIGH");
    #endif
    // Q will be HIGH (turn on system)
    delay(50);
    digitalWrite(s_pin, HIGH);
    digitalWrite(r_pin, LOW);
  }
  else{
    #if DEBUG
    Serial.println("butPin is LOW");
    #endif
    // Q will be LOW (turn off system)
    digitalWrite(s_pin, LOW);
    digitalWrite(r_pin, HIGH);
    
  }
  Serial.println("\n");
  
}
