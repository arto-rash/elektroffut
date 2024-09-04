#include <Servo.h>

#define trig A0
#define echo A1

Servo ser;

double cm;

int in1=2, in2=3, in3=4, in4=5;

void setup() {
  ser.attach(10);
  ser.write(90); //düz bax

  pinMode(trig, OUTPUT); //göndərir
  pinMode(echo, INPUT); //qəbul edir

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() { //forever
  dist();
  if(cm>1 && cm<20){
    ser.write(10); //look right
    delay(100);
    dist();
    ser.write(90);
    delay(100);
    if(cm<20 && cm>1){ //it should turn left
      digitalWrite(in1,1);
      digitalWrite(in2,0);

      digitalWrite(in3,0);
      digitalWrite(in4,1);
    }else { //it should turn right
      digitalWrite(in1,0);
      digitalWrite(in2,1);

      digitalWrite(in3,1);
      digitalWrite(in4,0);
    } delay(1200);
  }else if(cm<=1){
    digitalWrite(in1,0);
    digitalWrite(in2,1);

    digitalWrite(in3,0);
    digitalWrite(in4,1);
    delay(600);
  }

  //qabağa getsin
  digitalWrite(in1,1);
  digitalWrite(in2,0);

  digitalWrite(in3,1);
  digitalWrite(in4,0);

  delay(100);
}

void dist(){ //məsafə ölçən funksiya
  digitalWrite(trig, 0);
  delayMicroseconds(10);
  digitalWrite(trig, 1);
  delayMicroseconds(15);
  digitalWrite(trig, 0);

  cm = pulseIn(echo, 1) / 2 / 29;
}