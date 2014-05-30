/*
Functions for controlling a RedBot's motors, and setting up a Bluetooth connection.
 
 RedBot Pin Mapping
 0 - Hardware Serial TX (used for USB connection)
 1 - Hardware Serial RX (used for USB connection)
 2 - Motor A forwards/backwards
 3 - Available
 4 - Motor A brake (enable)
 5 - Motor A Speed
 6 - Motor B Speed
 7 - Motor B forwards/backwards
 8 - Motor B brake (enable)
 9 - Available
 10 - Available
 11 - Available
 
 A0 - Software Serial TX (also known as Pin14)
 A1 - Software Serial RX (also known as Pin15)
 A2 - Available
 A3 - Available
 A4 - Available
 A5 - Available
 A6 - Available
 A7 - Available
 
 */

#include <RedBot.h> // include the RedBot library
#include "notes.h" // Include the notes definitions to play tones

// create aliases for motor pins. This gives us a name rather than number which is easier to work with.
// motor A
#define motorafb 2     // Motor A on pin 2- forward/backwards 
#define motorab 4      // Motor A on pin 4 - brake
#define motorahs 5     // Motor A on pin 5 - Speed
// motor B
#define motorbfb 7     // Motor B on pin 7 - forward/backwards 
#define motorbb 8      // Motor B on pin 8 - brake
#define motorbhs 6     // Motor B on pin 6 - Speed


// Create an alias for the steering trim pot, for ease of use.
#define STEERING_TRIM_POT A2
// Create an alias for our bumper switch pin, for ease of use.
#define BUMPER_SWITCH_PIN 9
// Create an alias for our beeper pin, for ease of use.
#define BEEPER 11

// WN is the length of a whole note, in milliseconds, and 
// HN is the length of an half note
// QN is the length of an quarter note
// EN is the length of an eighth note
// SN is the length of a sixteenth note

#define beatLength 400
#define WN      beatLength*4
#define HN      beatLength*2
#define QN      beatLength
#define EN      beatLength/2
#define SN      beatLength/4

RedBotSoftwareSerial bluetooth; // create a "bluetooth" software serial instance for the Xbee Bluetooth card
// use bluetooth.print, bluetooth.read and bluetooth.write to use this serial port
RedBotMotor motors; // create a "motors" instance to use the motor functions
// use motors.drive, motors.pivot, motors.leftMotor and motors.rightMotor to drive the robot

// define global variables

char dataIn = 'S';           //Character/Data coming from the phone.  Initialized to S or stopped.
char command = 'S';      //Used to store alpha charachters coming from the phone that control robot direction
unsigned char velocity = 0;  //Used to store numeric charachters coming from the phone that control robot speed.
float opticalSensorReading; //Used to store raw optical sensor reading
double opticalSensorReportedDistance=40.0; // Used to store calibrated optical sensor distance measurement
int bumperSwitch; // create a variable called "bumperSwitch" for storing the reading from the bumper switch



void setup() 
{       
  blueToothStart();
  Serial.begin(9600);  // Begin the serial monitor at 9600bps
  pinMode(STEERING_TRIM_POT,INPUT);
  pinMode(BUMPER_SWITCH_PIN,INPUT);
  pinMode(BEEPER,OUTPUT);
}

void loop()
{ 
  bluetoothDrive();
  // proportionalControl();
  // bumpTurn();
  // driveSquare();
  // smallWorld();

}








