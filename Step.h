#include <iostream>
#include <time.h>
#include <sys/types.h>
#include "TempSensor.h"
#include <wiringPi.h>

class Step 
{ 
public:
    Step(int, double, string); 
    ~Step( );
    void setLaufzeit( int ); 
    void setTemp( double );
    void print(); 
    void test();    
private: 
    time_t m_startZeit;
    int m_laufZeit;
    double m_sollTemp;
    double m_ht;
    string m_tempSensorPath;
    TempSensor *m_ts;
}; 

