#include <AFMotor.h>
AF_DCMotor right_motor(1, MOTOR12_8KHZ);
AF_DCMotor left_motor(2, MOTOR12_8KHZ);

String readString;
int a=6 , b=3 , c=4 , d=2;
void setup() {
  Serial.begin(9600);
  right_motor.setSpeed(250);
  left_motor.setSpeed(250);
  pinMode(a,OUTPUT);
  
  pinMode(b,OUTPUT);
  
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);

}

void loop() {
  while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD"){
      digitalWrite(a,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,LOW);
            
      
      right_motor.run (FORWARD);
      left_motor.run (FORWARD);
      delay(500);
    }
    if (readString =="BACKWARD"){
      
      digitalWrite(a,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,LOW);
      right_motor.run (BACKWARD);
      left_motor.run (BACKWARD);
      delay(500);
    }
    if (readString =="LEFT"){
       digitalWrite(a,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,HIGH);
      right_motor.run (FORWARD);
      left_motor.run (BACKWARD);
      delay(500);
    }
    if (readString =="RIGHT"){
       digitalWrite(a,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,LOW);
      right_motor.run (BACKWARD);
      left_motor.run (FORWARD);
      delay(500);
    }
    if (readString =="STOP"){ 
      digitalWrite(a,LOW);
      digitalWrite(d,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      right_motor.run (RELEASE);
      left_motor.run (RELEASE);
      delay(500);
    }

    readString="";
  }
}
