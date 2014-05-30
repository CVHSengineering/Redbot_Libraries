/*
  RedBot Bump and Turn
 Written by Robert Hazlehurst, Castle View High School, robert.hazlehurst@dcsdk12.org
 
 When the robot's whisker sensor touches an object (robot is currently configured with 
 only one sensor, but ideally should have two), the robot stops, backs up, turns and
 continues driving foward until it hits another object.
 
 */

void bumpTurn()
{
  bumperSwitch=digitalRead(BUMPER_SWITCH_PIN); //read the sensor
  Serial.print("Bumper Switch = ");
  Serial.println(bumperSwitch);

  if(bumperSwitch == HIGH)
  {
    bluetooth.println("Hit Something, Turning Around"); //print status to cell phone screen
    motors.brake(); //stop
    dixie(); // sound the horn
    motors.drive(-100); // back up for half a second
    delay(500); 
    motors.pivot(500); // pivot turn counter clockwise for a quarter of a second
    delay(500); 
  }
  else
  {
    bluetooth.println("Driving Forward"); //print status to cell phone screen
    motors.leftDrive(112); //forward slowly, with compensation for tendency of robot to drift left
    motors.rightDrive(100);
  }
}

