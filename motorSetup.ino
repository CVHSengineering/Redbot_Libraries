void motorSetup() 
{       
  //Setup Motor A
  pinMode(motorafb, OUTPUT); //Initiates Motor  A pin
  pinMode(motorab, OUTPUT); //Initiates Brake  A pin
  pinMode(motorahs, OUTPUT); //Initiates Speed A pin

  //Setup Motor B
  pinMode(motorbfb, OUTPUT); //Initiates Motor B pin
  pinMode(motorbb, OUTPUT);  //Initiates Brake B pin
  pinMode(motorbhs, OUTPUT); //Initiates Speed B pin
}

