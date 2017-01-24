/*
    Switch Sensor
    Arduino Pro Mini
    Owen Ling
    January 2017

    Switch Sensor communicating with serial gateway over NRF24 radio.

    See wiki / documentation for more information on pinouts

    Can handle:
    - 1 to 3 switches and relays
    - 1 temperature sensor (using a Dallas 18b20)
    - 1 Photo Diode
    - 1 PIR (infra red motion detection)
    - 1 RGB output (temperature representation)
*/

/*------------------------------------------------------------------/
// Configuration
//-----------------------------------------------------------------*/

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
//  #define CHILD_ID_SWITCH_TWO 1
//  #define CHILD_ID_SWITCH_THREE 2
#define CHILD_ID_PD 3 //  photodiode
#define CHILD_ID_PIR 4
#define CHILD_ID_TEMP 5


//  Connected sensors configuration

//  If you're not using any switches / relays you can comment this line out.
#define MY_REPEATER_FEATURE

//  Due to limited ports on the board, we can only use three
//  switches here.
#ifdef CHILD_ID_SWITCH_ONE
  #define SWITCH_ONE A0;
  #define RELAY_ONE 4
#endif

#ifdef CHILD_ID_SWITCH_TWO
  #define SWITCH_TWO A1;
  //  #define RELAY_TWO 7
#endif

#ifdef CHILD_ID_SWITCH_THREE
  #define SWITCH_THREE A2;
  //  #define RELAY_THREE 8
#endif


#ifdef CHILD_ID_PD
  #define PD_PIN A3;
#endif

#ifdef CHILD_ID_PIR
  #define PIR_PIN A4;
#endif

#ifdef CHILD_ID_TEMP
  #define TEMP_PIN A5;
#endif

#define RGB_RED_PIN 3
#define RGB_GREEN_PIN 5
#define RGB_BLUE_PIN 6

//  Force a reading update to be sent to the gateway after N amount
//  of reads to prevent overly long time periods between updates from
//  being sent.
#define FORCE_UPDATE_AFTER_N_READS 200

//  Number of cycles before trying to grab readings from temp sensor
#define CYCLES_PER_READ 2000
/*------------------------------------------------------------------/
// End Configuration
//-----------------------------------------------------------------*/

/*------------------------------------------------------------------/
// Imports
//-----------------------------------------------------------------*/

#include <MySensors.h>

#ifdef CHILD_ID_TEMP
  #include <OneWire.h>
  #include <DallasTemperature.h>
#endif

/*------------------------------------------------------------------/
// End Imports
//-----------------------------------------------------------------*/

/*------------------------------------------------------------------/
// Global Variables
//-----------------------------------------------------------------*/

#ifdef CHILD_ID_SWITCH_ONE
  bool SWITCH_ONE_LIGHT_STATE = LOW;
  bool SWITCH_ONE_STATE = false;
  float SWITCH_ONE_VOLTAGE;
  MyMessage msgSWITCH_ONE(CHILD_ID_SWITCH_ONE, V_LIGHT);
#endif

#ifdef CHILD_ID_SWITCH_TWO
  bool SWITCH_TWO_LIGHT_STATE = LOW;
  bool SWITCH_TWO_STATE = false;
  float SWITCH_TWO_VOLTAGE;
  MyMessage msgSWITCH_TWO(CHILD_ID_SWITCH_TWO, V_LIGHT);
#endif

#ifdef CHILD_ID_SWITCH_THREE
  bool SWITCH_THREE_LIGHT_STATE = LOW;
  bool SWITCH_TRHEE_STATE = false;
  float SWITCH_TWO_VOLTAGE;
  MyMessage msgSWITCH_THREE(CHILD_ID_SWITCH_THREE, V_LIGHT);
#endif

//  Since the PIR goes high for a period of time rather than for
//  the duration that motion is detected we need this.
#ifdef CHILD_ID_PIR
  bool PIR_PREVIOUS_STATE;
  MyMessage msgPIR(CHILD_ID_PIR, V_TRIPPED);
#endif

#ifdef CHILD_ID_PD
  bool PD_PREVIOUS_STATE;
  MyMessage msgPD(CHILD_ID_PD, V_LIGHT_LEVEL);
#endif

#ifdef CHILD_ID_TEMP
  float TEMP_PREVIOUS_VALUE;
  byte TEMP_COUNTS_SINCE_LAST_SEND;
  MyMessage msgTEMP(CHILD_ID_TEMP, V_TEMP);
#endif

//  Present sensors and switches to gateway - controller.
void present()
{
  #ifdef CHILD_ID_PIR
    present(CHILD_ID_PIR, S_MOTION);
  #endif

  #ifdef CHILD_ID_PD
    present(CHILD_ID_PD, S_LIGHT_LEVEL);
  #endif

  #ifdef CHILD_ID_TEMP
    present(CHILD_ID_TEMP, S_TEMP);
  #endif
  
  #ifdef CHILD_ID_SWITCH_ONE
    present(CHILD_ID_SWITCH_ONE, S_LIGHT);
  #endif

  #ifdef CHILD_ID_SWITCH_TWO
    present(CHILD_ID_SWITCH_TWO, S_LIGHT);
  #endif

  #ifdef CHILD_ID_SWITCH_THREE
    present(CHILD_ID_SWITCH_THREE, S_LIGHT);
  #endif
}


void setup()
{ 
  pinMode(RBG_RED_PIN, OUTPUT);
  pinMode(RGB_GREEN_PIN, OUTPUT);
  pinMode(RGB_BLUE_PIN, OUTPUT);
  
  #ifdef CHILD_ID_SWITCH_ONE
    pinMode(SWITCH_ONE, INPUT_PULLUP);
    pinMode(RELAY_ONE, OUTPUT);
  #endif

  #ifdef CHILD_ID_SWITCH_TWO
    pinMode(SWITCH_TWO, INPUT_PULLUP);
    pinMode(RELAY_TWO, OUTPUT);
  #endif

  #ifdef CHILD_ID_SWITCH_THREE
    pinMode(SWITCH_THREE, INPUT_PULLUP);
    pinMode(RELAY_THREE, OUTPUT);
  #endif

  #ifdef CHILD_ID_PIR
    pinMode(PID_PIN, INPUT);
  #endif

  #ifdef CHILD_ID_PD
    pinMode(PD_PIN, INPUT);
  #endif

  #ifdef CHILD_ID_TEMP
    pinMode(TEMP_PIN, INPUT);
  #endif
}


void loop()
{

}
