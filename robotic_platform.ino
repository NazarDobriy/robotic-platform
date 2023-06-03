#include <Ultrasonic.h>
#include <SoftwareSerial.h>

char cmd = ' ';
Ultrasonic ultrasonic (11, 12);
SoftwareSerial bluetooth (0, 1);

void setup() {
  bluetooth.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  analogWrite(5, 255);
  analogWrite(10, 255);
}

void loop() {
  if (bluetooth.available()) {

    if (ultrasonic.read() < 10) {
      stop();
    }

    cmd = bluetooth.read();
    
    if (cmd == 'F') {
      forward();
    } else if (cmd == 'B') {
      back();
    } else if (cmd == 'L') {
      left();
    } else if (cmd == 'R') {
      right();
    } else if (cmd == 'S') {
      stop();
    }
  }
}

void forward() {
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void back() {
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}

void left() {
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void right() {
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void stop() {
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
