void leftPivotTurn(int time, unsigned char motorSpeed)
{

  digitalWrite(motorafb, LOW); //Establishes forward direction of Motor A
  digitalWrite(motorab, LOW);   //Disengage the Brake for Motor A
  analogWrite(motorahs, motorSpeed);   //Spins the motor on Motor A at full speed
  digitalWrite(motorbfb, HIGH); //Establishes forward direction of Motor B
  digitalWrite(motorbb, LOW);   //Disengage the Brake for Motor B
  analogWrite(motorbhs, motorSpeed);   //Spins the motor on Motor B at full speed
  digitalWrite(motorab, HIGH);   //Disengage the Brake for Motor B
//  delay(time);
//  analogWrite(motorahs, 0);    //stop Motor A
//  analogWrite(motorbhs, 0);    //stop Motor B

} 
