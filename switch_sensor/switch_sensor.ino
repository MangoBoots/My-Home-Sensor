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

//  MySensor Library Configuration

//  Define radio type to be used.
//  NOTE: radio definition must be delcared before anything else.
#define MY_RADIO_NRF24

//  Comment out to disable debugging.
#define MY_DEBUG

//  Set node ID
#define MY_NODE_ID 1

//  Set child ID
#define CHILD_ID_SWITCH_ONE 0
// #define CHILD_ID_SWITCH_TWO 1
// #define CHILD_ID_SWITCH_THREE 2
#define CHILD_ID_PD 3 //  photodiode
#define CHILD_ID_PIR 4
#define CHILD_ID_TEMP 5


//  Connected sensors configuration

// Due to limited ports on the board, we only support up to three
// switches here.
#define SWITCH_ONE A0;
// #define SWITCH_TWO A1;
// #define SWITCH_THREE A2;
#define RELAY_ONE 4
// #define RELAY_TWO 7
// #define RELAY_THREE 8

#define PD_PIN = A3;

#define PIR_PIN = A4;

#define TEMP_PIN = A5;


/*------------------------------------------------------------------/
// End Configuration
/*-----------------------------------------------------------------*/

void setup() {
  //  put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
