/*
  Calibration of Infrared Proximity opticalSensorReading Long Range - Sharp GP2Y0A02YK0F
  SparkFun Part#: SEN-08958 https://www.sparkfun.com/products/8958
  By Robert Hazlehurst, Castle View High School robert.hazlehurst@dcsdk12.org
  
  for use on RedBot Robot SparkFun Part#: ROB-12032 https://www.sparkfun.com/products/12032
  with RN42-XV Bluetooth Module - PCB Antenna installed in the Xbee port
  SparkFun Part#: WRL-11601 https://www.sparkfun.com/products/11601
  
  Equation:
  opticalSensorReportedDistance (in inches) = 6202.3*opticalSensorReadingReading^-1.056 fit with an R² = 0.9914
  
    Raw Data: 
  opticalSensorReading	opticalSensorReportedDistance (In)
  502	        8
  434	        10
  379	        12
  329	        14
  283	        16
  257	        18
  229	        20
  213	        22
  199	        24
  139	        36
  91	        48

*/


void readOpticalSensor() 
{
  const char opticalSensorPort = A3;
  
  opticalSensorReading = analogRead(opticalSensorPort); //read the opticalSensorReading
  opticalSensorReportedDistance = 6202.3*pow(opticalSensorReading,-1.056); //apply cal curve to convert to inches
  // bluetooth.print("opticalSensorReportedDistance = "); //print opticalSensorReportedDistance to cell phone screen
  // bluetooth.println(opticalSensorReportedDistance);
}

