void sensorRead()
{
  sum=0;
  pos = 0;
  for (int i = 0; i < 8; i++)
  {
    s[i] = analogRead(i);
   /* if (s[i] < trash[i])
    {
      s[i] = 1;
      digitalWrite(led[i], HIGH);
    }
    else
    {
      s[i] = 0;
      digitalWrite(led[i], LOW);
    }*/
    sum += s[i];
  Serial.print(s[i]);
  Serial.print("||");
  }
  Serial.println();

  pos = (s[0]*0 + s[1]*1000 + s[2]*2000 + s[3]*3000 + s[4]*4000 + s[5]*5000 + s[6]*6000 + s[7]*7000)/sum;  
}
