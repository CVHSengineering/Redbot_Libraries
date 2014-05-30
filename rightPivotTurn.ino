void rightPivotTurn(int time, unsigned char motorSpeed)
{
  digitalWrite(motorafb, HIGH); //Establishes forward direction of Motor A
  digitalWrite(motorab, LOW);   //Disengage the Brake for Motor A
  analogWrite(motorahs, motorSpeed);   //Spins the motor on Motor A at motorSpeed
  digitalWrite(motorbfb, LOW); //Establishes forward direction of Motor B
  digitalWrite(motorbb, LOW);   //Disengage the Brake for Motor B
  analogWrite(motorbhs, motorSpeed);   //Spins the motor on Motor B at motorSpeed
  digitalWrite(motorbb, HIGH);   //Disengage the Brake for Motor B
  //  delay(time);
  //  analogWrite(motorahs, 0);    //stops Motor A
  //  analogWrite(motorbhs, 0);    //stops Motor B

} 

