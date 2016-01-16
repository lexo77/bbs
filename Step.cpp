#include "Step.h"
using namespace std;

Step::Step (int laufZeit, double sollTemp, string tempSensorPath)
{
  m_laufZeit = laufZeit;
  m_sollTemp = sollTemp;
  m_tempSensorPath = tempSensorPath;
  m_ht = 1;
  m_ts = new TempSensor(m_tempSensorPath);
  if (wiringPiSetup() == -1)
    cout << "Fehler beim Initialisieren von WiringPi" << "\n"; 
}

Step::~Step ( )
{
  cout << "destructor Step" << "\n";
  delete m_ts;
}

void Step::setLaufzeit(int laufZeit) 
{ 
  m_laufZeit = laufZeit; 
} 

void Step::setTemp(double sollTemp) 
{ 
  m_sollTemp = sollTemp; 
} 

void Step::print()
{
  cout << "Laufzeit: " << m_laufZeit << "\n";
  cout << "SollTemp: " << m_sollTemp << "\n";
  cout << "TempSensorPath: " << m_tempSensorPath << "\n";
}
 
void Step::test()
{
  time_t istZeit;
  double istTemp = m_ts->getTemp();
  
  cout << "istTemp: " << istTemp << " sollTemp: " << m_sollTemp << "\n";
  char buffer[26];
  struct tm * timeinfo;
  timeinfo = localtime (&istZeit);
  strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", timeinfo);

  cout << "istZeit: " << buffer << " sollZeit: " << m_startZeit + m_laufZeit << "\n";

  if (m_startZeit != 0 ) 
  {
    istZeit = time(NULL);
    cout << istZeit - m_startZeit << "\n";
  }
  if (m_startZeit == 0 || (m_startZeit + m_laufZeit) > istZeit)
  {
    if (istTemp < m_sollTemp - m_ht)
    {
        digitalWrite(0, 1);
    }
    else
    {
      if (m_startZeit == 0) m_startZeit = time(NULL);
      digitalWrite(0, 0);
    }
  }
  else
  {
    cout << "Rast beendet!\n";
  }
}

/*
int main(int argc, char *argv[]) 
{ 
    Step *s = new Step(0, 0, "/sys/bus/w1/devices/28-000006e29a0d/w1_slave"); 
    
    s->setLaufzeit (60);
    s->setTemp(21);
    s->test(); 
    s->print(); 

    delete s; 

    return 0; 
} 
*/

