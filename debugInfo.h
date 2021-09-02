// add the following line in your code to add debug info
// #define DEBUG
// #define DEBUG1
// #define DEBUG2
//
// 3 levels of debug messages
//   - DEBUG used for the high level messages, prints DEBUG_PRINT messages
//   - DEBUG1 for more detailed messages, prints DEBUG_PRINT and DEBUG_L1_PRINT messages
//   - DEBUG2 for more verbosity, prints DEBUG_PRINT, DEBUG_L1_PRINT and DEBUG_L2_PRINT messages
//
// Beware that timeStartx and timeEndx are global variables
// so time measurements for one level of messages shall not be nested
//


#if defined(DEBUG2)

unsigned long int timeStart2, timeEnd2;
#define DEBUG_L2_PRINT(x) Serial.print(x);
#define DEBUG_L2_PRINTLN(x) Serial.println(x);
#define DEBUG_L2_PRINT2(x,y) Serial.print(x,y);
#define DEBUG_L2_PRINTLN2(x,y) Serial.println(x,y);
#define DEBUG_L2_PRINTF(x,y) Serial.printf(x,y);
#define DEBUG_L2_TIME_START timeStart2 = millis();
#define DEBUG_L2_TIME_END timeEnd2 = millis();
#define DEBUG_L2_TIME_PRINT DEBUG_PRINT(timeEnd2 - timeStart2); DEBUG_PRINTLN("ms");

#else

#define DEBUG_L2_PRINT(x)
#define DEBUG_L2_PRINTLN(x)
#define DEBUG_L2_PRINT2(x,y)
#define DEBUG_L2_PRINTLN2(x,y)
#define DEBUG_L2_PRINTF(x,y) 
#define DEBUG_L2_TIME_START
#define DEBUG_L2_TIME_END
#define DEBUG_L2_TIME_PRINT

#endif

#if defined(DEBUG1) || defined(DEBUG2)

unsigned long int timeStart1, timeEnd1;
#define DEBUG_L1_PRINT(x) Serial.print(x);
#define DEBUG_L1_PRINTLN(x) Serial.println(x);
#define DEBUG_L1_PRINT2(x,y) Serial.print(x,y);
#define DEBUG_L1_PRINTLN2(x,y) Serial.println(x,y);
#define DEBUG_L1_PRINTF(x,y) Serial.printf(x,y);
#define DEBUG_L1_TIME_START timeStart1 = millis();
#define DEBUG_L1_TIME_END timeEnd1 = millis();
#define DEBUG_L1_TIME_PRINT DEBUG_PRINT(timeEnd1 - timeStart1); DEBUG_PRINTLN("ms");

#else

#define DEBUG_L1_PRINT(x)
#define DEBUG_L1_PRINTLN(x)
#define DEBUG_L1_PRINT2(x,y)
#define DEBUG_L1_PRINTLN2(x,y)
#define DEBUG_L1_PRINTF(x,y) 
#define DEBUG_L1_TIME_START
#define DEBUG_L1_TIME_END
#define DEBUG_L1_TIME_PRINT

#endif

#if defined(DEBUG) || defined(DEBUG1) || defined(DEBUG2)

unsigned long int timeStart, timeEnd;
#define DEBUG_PRINT(x) Serial.print(x);
#define DEBUG_PRINTLN(x) Serial.println(x);
#define DEBUG_PRINT2(x,y) Serial.print(x,y);
#define DEBUG_PRINTLN2(x,y) Serial.println(x,y);
#define DEBUG_PRINTF(x,y) Serial.printf(x,y);
#define DEBUG_TIME_START timeStart = millis();
#define DEBUG_TIME_END timeEnd = millis();
#define DEBUG_TIME_PRINT DEBUG_PRINT(timeEnd - timeStart); DEBUG_PRINTLN("ms");

#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#define DEBUG_PRINT2(x,y)
#define DEBUG_PRINTLN2(x,y)
#define DEBUG_PRINTF(x,y) 
#define DEBUG_TIME_START
#define DEBUG_TIME_END
#define DEBUG_TIME_PRINT

#endif

