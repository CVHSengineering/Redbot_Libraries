void forward(int time, unsigned char motorSpeed)
{
  unsigned char leftMotorSpeed, rightMotorSpeed;
  int potReading = analogRead(STEERING_TRIM_POT);
  float motorRatio = (float)potReading/512.0; //motorRatio > 1 left motor too fast / robot goes right, motorRatio < 1 right motor too fast / robot goes left
  if(motorRatio>1.0)
  {
    leftMotorSpeed=motorSpeed/motorRatio; // slow left motor down
    rightMotorSpeed=motorSpeed; //run right motor at desired speed
  }
  else
  {
    leftMotorSpeed=motorSpeed; //run left motor at desired speed
    rightMotorSpeed=motorSpeed*motorRatio; // slow right motor down
  }
  bluetooth.print("potReading = ");
  bluetooth.print(potReading,DEC);
  bluetooth.print("motorRatio = ");
  bluetooth.println(motorRatio, 3);
  bluetooth.print("leftMotorSpeed = ");
  bluetooth.print(leftMotorSpeed, DEC);
  bluetooth.print(" rightMotorSpeed = ");
  bluetooth.println(rightMotorSpeed, DEC);
  digitalWrite(motorafb, HIGH); //Establishes forward direction of Motor A
  digitalWrite(motorab, LOW);   //Disengage the Brake for Motor A
  analogWrite(motorahs, leftMotorSpeed);   //Spins the motor on Motor A at leftMotorSpeed
  digitalWrite(motorbfb, HIGH); //Establishes forward direction of Motor B
  digitalWrite(motorbb, LOW);   //Disengage the Brake for Motor B
  analogWrite(motorbhs, rightMotorSpeed);   //Spins the motor on Motor B at rightMotorSpeed
//  delay(time);
//  analogWrite(motorahs, 0);    //stop Motor A
//  analogWrite(motorbhs, 0);    //stop Motor B
} 

