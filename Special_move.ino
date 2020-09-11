void hardBreak()
{
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, HIGH);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, HIGH);
}
void seiram_break()
{
  hardBreak();
  run(80,80);
  delay(30);
  run(-255, -255);
  delay(30);
  stop();
}

void stop()
{
  //  wheel(-200, -200);
  //  delay(50);
  run(0, 0);
  delay(50);
}



void RightTurn() {

 while (analogRead(A5) < trash[5]) {
    run(120, -120);
  }

}

void LeftTurn() {

  while (analogRead(A2) < trash[2]) {
    run(-120, 120);

  }
}


void blindLeft90() {
  {
      run(-200, 200);
      delay(315);
  }
}

void blindRight90() {
  {
      run(200, -200);
      delay(315);

  }
}
