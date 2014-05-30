void proportionalControl()
{
  float target=20;
  float kp=30;
  readOpticalSensor();
  float error=float(opticalSensorReportedDistance)-target;
  float motorSpeed=error*kp;
  if(motorSpeed>255.0)
  {
    motorSpeed=255.0; 
  }
  if(motorSpeed<-255.0)
  {
    motorSpeed=-255.0; 
  }
  bluetooth.print("dist = ");
  bluetooth.print(opticalSensorReportedDistance);
  bluetooth.print("err = ");
  bluetooth.print(error);
  bluetooth.print("motor = ");
  bluetooth.println(motorSpeed);
  motors.drive(int(motorSpeed));
}
