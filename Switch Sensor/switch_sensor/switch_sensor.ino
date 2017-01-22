/*
 *  Switch Sensor
 *  Arduino Pro Mini
 *  Owen Ling
 *  January 2017
 *  
 *  Switch Sensor communicating with serial gateway over NRF24 radio.
 * 
 *  See wiki / documentation for more information on pinouts
 * 
 *  Can handle: 
 *  - 1 to 3 switches and relays
 *  - 1 temperature sensor (using a Dallas 18b20)
 *  - 1 Photo Diode
 *  - 1 PIR (infra red motion detection)
 *  - 1 RGB output (temperature representation) 
 */

/*------------------------------------------------------------------/
// Configuration
/*-----------------------------------------------------------------*/

// Define radio type to be used.
// NOTE: radio definition must be delcared before anything else.
#define MY_RADIO_NRF24

// Comment out to disable debugging.
#define MY_DEBUG

// Enable or disable sensors.
bool PIR = true;
bool TEMP = true;
bool PD = true;

// Select number of switches, max is 3 (limited to three due to board)
byte NO_OF_SWITCHES = 2;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
