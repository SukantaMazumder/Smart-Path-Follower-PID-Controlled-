int irup()
{
  int total = 0;
  sensorRead();
  total = s[0]+s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7];
  return total;
}
