void readBlueTooth()
{
  if (bluetooth.available() > 0)    //Check for data on the serial lines.
  {   
    dataIn = bluetooth.read();  //Get the character sent by the phone and store it in 'dataIn'.

    if (dataIn == 'F')
    {     
      command = 'F';
    }  
    else if (dataIn == 'B')
    { 
      command = 'B'; 
    }
    else if (dataIn == 'L')  
    { 
      command = 'L';
    }
    else if (dataIn == 'R')  
    { 
      command = 'R';
    } 
    else if (dataIn == 'S') 
    {
      command = 'S';
    }
    else if (dataIn == '0') 
    {
      velocity = 0;
    }
    else if (dataIn == '1') 
    {
      velocity = 25;
    }
    else if (dataIn == '2') 
    {
      velocity = 50;
    }
    else if (dataIn == '3') 
    {
      velocity = 75;
    }
    else if (dataIn == '4') 
    {
      velocity = 100;
    }
    else if (dataIn == '5') 
    {
      velocity = 125;
    }
    else if (dataIn == '6') 
    {
      velocity = 150;
    }
    else if (dataIn == '7') 
    {
      velocity = 175;
    }
    else if (dataIn == '8') 
    {
      velocity = 200;
    }
    else if (dataIn == '9') 
    {
      velocity = 225;
    }
    else if (dataIn == 'q') 
    {
      velocity = 255;
    }

  }
}
