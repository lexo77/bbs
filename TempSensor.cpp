#include "TempSensor.h"
using namespace std;

//TempSensor::TempSensor(const char *path)
TempSensor::TempSensor(string path)
{
  m_sensor = path;
  //m_device = fopen(m_sensor.c_str(), "r");
}

TempSensor::~TempSensor()
{
  cout << "destructor TempSensor" << "\n";
  //fclose(m_device);  
}

double TempSensor::getTemp()
{
  char crcVar[5];  
  double temperature = -1;
  //rewind(m_device);
  m_device = fopen(m_sensor.c_str(), "r");
  if (m_device == NULL)
  {
    cout << "Check connections " << m_sensor << "\n";
    perror("\n");
  }
  if (m_device != NULL)
  {
    if (!ferror(m_device))
    {
      fscanf(m_device, "%*x %*x %*x %*x %*x %*x %*x %*x %*x : crc=%*x %s", crcVar);
      
      if (strncmp(crcVar, "YES", 3) == 0)
      {
        fscanf(m_device, "%*x %*x %*x %*x %*x %*x %*x %*x %*x t=%lf", &temperature);
        temperature /= 1000.0;
      }
    }
    else cout << "bullshit" << "\n";
  }
  fclose(m_device);
  
  return temperature;
}

/*
int main(int argc, char *argv[])
{
  TempSensor *t;
  string sensorPath = "/sys/bus/w1/devices/28-000006e29a0d/w1_slave";
  t = new TempSensor(sensorPath);
  cout << "TempSensor: " << t->getTemp() << "\n";
  delete t;
  return 0;
}
*/




