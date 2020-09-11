int PID()  
{
  int error=0;
  sensorRead();
  error = 3500-pos;
  I += error;

  if(I>255) I = 255;
  if(I<-255) I = -255;

  pid = (error/kp) + (I/ki) + ((error - last_error)*kd);
  last_error = error;
  //Serial.println(error);

  lms = l_base-pid;
  rms = r_base+pid;

  if(lms>256) lms = 255;
  if(rms>256) rms = 255;
  if(lms<-256) lms = -255;
  if(rms<-256) rms = -255;

  run(lms,rms);

  return error;
}
