#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class TempSensor
{
public:
  //TempSensor(const char *);
  TempSensor(string);
  ~TempSensor();
  double getTemp(); 
private:
  string m_sensor;
  FILE *m_device;
};

