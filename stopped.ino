void stopped()
{
  digitalWrite(motorab, HIGH);   //Disengage the Brake for Motor A
  digitalWrite(motorbb, HIGH);   //Disengage the Brake for Motor A
  analogWrite(motorahs, 0);    //Spins the motor on Motor A at half speed
  analogWrite(motorbhs, 0);   //Spins the motor on Motor B at full speed
} 

