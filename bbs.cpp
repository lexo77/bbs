//g++ -Wall -o bbs bbs.cpp -lsqlite3 -lwiringPi
//
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string.h>
//sudo apt-get install libsqlite3-dev
#include <sqlite3.h> 

//#include <wiringPi.h>
#include "Step.h"
#define BUF 8192

using namespace std;

int main()
{
  double sollTemp = 21 ;
  int laufZeit = 60;
  double istTemp;
  time_t startZeit = 0 ;
  time_t istZeit;
  int ht = 1;

  char puffer[BUF];
  int fd;
  int n;
  
  cout << "Start BBS" << "\n";
  
  //Initialisierung WiringPi
  if (wiringPiSetup() == -1)
    return 1;
  
  //NamedPipe erzeugen und oeffnen 
  remove ("fifo1.1");
  if(mkfifo("fifo1.1", 0777) < 0)
  {
    fprintf(stderr,"Konnte keine FIFO erzeugen!!\n");
    exit(0);
  }
  
  fd=open("fifo1.1", O_RDONLY|O_NONBLOCK);
  if(fd == -1)
  {
    perror("open : ");
    exit(0);
  }
  
 
   /* 
  ifstream np ("fifo1.1", ios::in|ios::binary|ios::ate);
  cout << "x2.5\n";
  if (np.is_open() == false)
  {
    perror("open : ");
    exit(0);
  }
  */
 
  //Pollingschleife bis alle Aufgaben erledigt sind  
  Step *s = new Step(60, 22, "/sys/bus/w1/devices/28-000006e29a0d/w1_slave");
  int x = 0;
  while(1) 
  {
    x++;
    cout << "\n" << x << "\n";
    //Eingaben aus der Pipe abfragen
    n = read(fd,puffer,BUF);
    //n = file.read (puffer, BUF);

    if(n != 0)
    {
      cout << "Puffer: |" << puffer << "|\n";
      if (strcmp(puffer,"exit") == 0)
      {
        cout << "exit" << "\n";
        return(0);
        exit(0);
      }
      if (strcmp(puffer,"hallo") == 0)
      {
        cout << "Hallo Welt" << "\n";
      }
    }
    s->test();  
    
    sleep(2);
  }
  delete s;
 
  //if (wiringPiSetup() == -1)
  //  return 1;
  
  //Akutelle Temeratur
  //cout << "Temp: " << readTemp("/sys/bus/w1/devices/28-000006e29a0d/w1_slave") << "\n";

  //Zeit 
  //time_t start = time(NULL); 
  //cout << "Start: " << start << "\n";   
  
  
 return 0;
}
