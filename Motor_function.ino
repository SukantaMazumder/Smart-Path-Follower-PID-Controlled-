void run(int x, int y)
{
  if (x > 0)
  {
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
  }
  if (y > 0)
  {
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
  }
  if (x < 0)
  {
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    x = abs(x);
  }

  if (y < 0)
  {
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, HIGH);
    y = abs(y);
  }

  
  analogWrite(lme, x);
  analogWrite(rme, y);
}
