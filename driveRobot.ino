void driveRobot(char driveCommand, unsigned char velocity) {

  switch (driveCommand) {
  case 70 : //if incoming data is a F, move forward
    forward(1000,velocity);  
    break;           
  case 66 : //if incoming data is a B, move forward
    backward(1000,velocity);
    break;           
  case 76 : //if incoming data is a L, move forward
    leftPivotTurn(300,90);
    break;                   
  case 82 : //if incoming data is a R, move forward
    rightPivotTurn(300,90);
    break;    
  case 83 : //if incoming data is a S, move stop
    stopped();
    break;               
  } //continue case conversion HERE  
}
