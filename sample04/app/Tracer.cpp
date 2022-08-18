#include "Tracer.h" // <1>
#include <stdio.h>
Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2) { // <2>
  }

void Tracer::init() {
  init_f("Tracer");
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::run() {
  const float Kp = 0.77;
  const int target = 50;
  const int bias = -10;

  msg_f("running...", 1);
  int brightness = colorSensor.getBrightness();
  int diff =brightness - target;
  printf("%d\n", brightness); 
  float turn = Kp * diff + bias;
  leftWheel.setPWM(pwm - turn);
  rightWheel.setPWM(pwm + turn); 
}

