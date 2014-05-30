/* 
 When plugging a bluetooth card into the xbee port on the RedBot in "hardware serial" mode the card
 uses pins 0 and 1 on the board.  The problem is, those are the same pins used by the USB for downloading
 code to the board.  So when using the bluetooth card in "hardware serial" mode there is a conflict between
 the bluetooth board and the USB; code cannot be downloaded with the bluetooth card installed.  So the
 bluetooth board either has to be removed, or the switch on the board set to software serial during code download, 
 and then set back to hardware serial after code download.
 
 The advantage of using software serial is the bluetooth board is mapped to other pins, which clears the conflict
 with the USB port.  The downside is two pins on the board (pins A0 and A1, also known as pins 14 and 15) cannot
 be used for other purposes.
 */

void blueToothStart()
{
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print $ three times individually to put the Bluetooth card into command mode
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600 
}

