#include<EEPROM.h>
#define lm1 5
#define lm2 6
#define rm1 7
#define rm2 8
#define lme 9
#define rme 10
int s[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int led[8] = {14, 15, 16, 17, 18, 20, 21, 22};
int sum,pos;
int pid=0;
int l_base = 255;
int r_base = 255;
int I = 0,last_error = 0;
int lms = 0;
int rms = 0;
int kp = 9;
int kd =30;//16;
int ki = 22;//12;
int count = 0;

//for calibration & store
#define calout  53
#define calin 49  // use led to indiacte that calirbation is started 

int minimum[] = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024};
int maximum[] = {0, 0, 0, 0, 0, 0, 0, 0};
int trash[] = {0, 0, 0, 0, 0, 0, 0, 0}; // theshhold value storing


void cal() {
  digitalWrite(calout, HIGH); // use led to indiacte that calirbation is started
  delay(2000);
  run(-200, 200);
  int c = 0;


  while (c < 10000) {
    for (int i = 0; i < 8; i++) {
      s[i] = analogRead(i);
      maximum[i] = max(maximum[i], s[i]);
      minimum[i] = min(minimum[i], s[i]);
    }

    c++;
  }
  run(0, 0);
  delay(500);
  for (int i = 0; i < 8; i++) trash[i] = ( maximum[i] + minimum[i]) / 2;
  for (int i = 0; i < 8; i++) {
    EEPROM.write(i, trash[i] / 5 );
    delay(10);

  }

  digitalWrite(calout, LOW);
  return;
}

void setup() {
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(lme, OUTPUT);
  pinMode(rme, OUTPUT);
  pinMode(calin, INPUT); // switch input
  pinMode(calout, OUTPUT);


  if (digitalRead(calin) == HIGH) cal();


  for (int i = 0; i < 8; i++) trash[i] = EEPROM.read(i) * 5;

  for (int i = 0; i < 8; i++)
  {
    pinMode(led[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  line_follow();

}
