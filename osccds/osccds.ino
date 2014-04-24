/*
  OpenSource Club Office
  
  Operates the OSC CDS Shield
  
  Main Operations:
    1. Office
      * Send 'O' over serial comm
      * 1 or 0 will be returned 
      * 1 = Someone is predicted in the 
      *   the office   
    2. Calibrate
      * Send 'C' over Serial comm
      *   Every 1/4 second the CDS value
      *   Will be printed
      * Change CDS_THRESHOLD to the
      *   value that corresponds to 
      *   the dark room cutoff
      * Any new value on Serial will stop 
      *   calibration
  
  Authors:
    bsilvereagle - 21 Apr 14
 */
 

//Slightly hackish
// To keep board size small, GPIO pins
// are driven HIGH/LOW to function as VCC
// and GND pins. Do not try this at home
int VCC     = A0;
int GND     = A1;
int LED     = A2;
int CDS     = A3;
int SWITCH  = A4;

//Is someone here?
boolean office = false;

//Serial Bad
int BAUD_RATE = 9600;
//Storage
int readByte = 0;
//Timer
unsigned long time = 0;
unsigned long MAX_DURATION = 300000; //60000*minutes
//CDS
int CDS_THRESHOLD = 500;


void setup()
{                
  // Initialize pin states
  pinMode(VCC, OUTPUT); 
  pinMode(GND, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT);
  
  //Establish GND, VCC pins
  digitalWrite(VCC, HIGH);
  digitalWrite(GND, LOW); //GND the board  
  
  digitalWrite(SWITCH, HIGH);
  
  //Start up the Serial Comm
  Serial.begin(BAUD_RATE);
  Serial.write("CDS Shield Started\n");
}

//Listens for serial input and responds accordingly
void listen_and_respond()
{
  //Check for data on the serial line
  if(Serial.available() > 0)
  {
    readByte = Serial.read();
    //We have data, check to see if calibration
    //  or office status is wanted 
    if(readByte == 'C')
    {
      //Calibration
      while(Serial.available() == 0){
        Serial.println(analogRead(CDS));
        delay(500);
     } 
    }
    else if(readByte == 'O')
    {
      //Report back the state of the office
      Serial.print(office,DEC);  
    }
  }
}

void loop() {
  //Run the main loop at 10Hz
  delay(100);
  
  listen_and_respond();
  
  //Check Switch State
  //  Inverted for pullup
  if(!digitalRead(SWITCH))
  {
    //Someone is here
    office = true;
    //Start the X minute timer
    time = millis();    
  }; 
  
  //Check X minute timer
  if((millis() - time) > MAX_DURATION)
  {
    office = false;  
    time = 0;
  }
  
  //Check CDS
  if((analogRead(CDS) < CDS_THRESHOLD) && (time == 0))
  {
    office = false; 
    time = 0;
  }
  else 
  { 
    office = true;
  }
  
  office ? digitalWrite(LED,HIGH) : digitalWrite(LED,LOW);  
}
