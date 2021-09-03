# debugInfo
Some macro to add optional debug information in your Arduino program  

## Why
In every program there is a moment when one shall add some Serial.print to help debug a piece of code.  
When the code is working the Serial.print shall be supressed (or commented) and if there is another problem later they shall be added again (or uncommented).

## The solution
Macros that can be activated/deasctivated at will.  
Macros that when deactivated take no room in flash.

The solution is a collection of #define that generate code when active and generate no code when deactivated.  
When active, the following line generates a Serial.print()  
When not active, no code is generated  
```
#if defined(DEBUG)
#define DEBUG_PRINT(x) Serial.print(x);
#else
#define DEBUG_PRINT(x) 
#endif
```
## How it works
### How to activate/deactivate
There are 3 levels of debug messages  
- DEBUG used for the high level messages, prints DEBUG_PRINT messages
- DEBUG1 for more detailed messages, prints DEBUG_PRINT and DEBUG_L1_PRINT messages
- DEBUG2 for even more detailed messages, prints DEBUG_PRINT, DEBUG_L1_PRINT and DEBUG_L2_PRINT messages

To define the 3 levels of debug messages, the macro names start with DEBUG, DEBUG_L1 and DEBUG_L2  

Uncomment one of the following lines at the begining of your code to add debug info, before #include <debugInfo.h>  
```
//#define DEBUG
//#define DEBUG1
//#define DEBUG2
#include <debugInfo.h>
```
### The debug macros
- DEBUG_PRINT(x), is a Serial.print(x);  
DEBUG_PRINTLN(x), is a Serial.println(x);  
It is the usual print from the Arduino library  
- DEBUG_PRINT2(x,y), is a Serial.print(x,y);  
DEBUG_PRINTLN2(x,y), is a Serial.println(x,y);  
It is the usual print from the Arduino library with the optionnal data format  
- DEBUG_PRINTF(x,y), is a Serial.printf(x,y);  
It is the standard printf  
- DEBUG_TIME_START, is  timeStart = millis();  
Sets timeStart to the current time. Use at the beginning of the piece of code to time.  
- DEBUG_TIME_END, is timeEnd = millis();  
Sets timeEnd to the current time. Use at the end of the piece of code to time.  
- DEBUG_TIME_PRINT, is DEBUG_PRINT(timeEnd - timeStart); DEBUG_PRINTLN("ms");  
Prints the elapsed time  


Beware that timeStart and timeEnd are global variables, but each level of debug has its own set of variables,
so time measurements for one level of messages shall not be nested


