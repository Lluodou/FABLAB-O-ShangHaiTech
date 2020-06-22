#include<Servo.h>
Servo trigger;
Servo vertical;
Servo horizontal;
void setup() {
  // put your setup code here, to run once:
  trigger.attach(9);
  vertical.attach(3);
  horizontal.attach(5);
  Serial.begin(60);
  pinMode(2,INPUT);
  pinMode(A0,INPUT);
}
int fire_if;
int vertical_move;
double vertical_angle=0;
double vertical_speed=0.005;
int horizontal_move;
double horizontal_angle=90;
double horizontal_speed=0.005;
void loop() {
  // put your main code here, to run repeatedly:
  fire_if=digitalRead(2);
  vertical_move=analogRead(A0);
  horizontal_move=analogRead(A1);
  if(fire_if==1){
    trigger.write(180);
  }
  else{
    trigger.write(90);  
  }
  double vertical_delta=0;  
  if(vertical_move<508 or vertical_move>520){
    vertical_delta=vertical_speed*((double)(vertical_move-514)/1028);  
  }
  
  if(vertical_delta>0){
    if(vertical_angle+vertical_delta<90) vertical_angle=vertical_angle+vertical_delta;
  }
  if(vertical_delta<0){
    if(vertical_angle+vertical_delta>0) vertical_angle=vertical_angle+vertical_delta;
  }
  vertical.write(vertical_angle);
  double horizontal_delta=0;  
  if(horizontal_move<490 or horizontal_move>502){
    horizontal_delta=horizontal_speed*((double)(horizontal_move-496)/1028);  
  }
  if(horizontal_delta>0){
    if(horizontal_angle+horizontal_delta<190) horizontal_angle=horizontal_angle+horizontal_delta;
  }
  if(horizontal_delta<0){
    if(horizontal_angle+horizontal_delta>0) horizontal_angle=horizontal_angle+horizontal_delta;
  }
  horizontal.write(horizontal_angle);
}
