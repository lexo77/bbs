/****************************************************************
Datei     : config.cpp
Author    : Oed
Datum     : 08.01.2016
Parameter :         
Return    : 
Aufgabe   : Test der Kalsse config.cpp
Comp.     : c++ config.cpp -o config
****************************************************************/
#include "rezept.h"

Rezept::Rezept( string fileName ) 
{ 
  cout << "Konstruktor von 'Config'\n"; 
  m_fileName = fileName;
  this->readFile();
} 

Rezept::~Rezept() 
{ 
  cout << "Destruktor von 'Config'\n"; 
} 

string Rezept::getBez( int i )
{
  return m_rez.at(i).bez;
}

double Rezept::getTemp( int i )
{
  return m_rez.at(i).temp;
}

int Rezept::getZeit( int i )
{
  return m_rez.at(i).zeit;
}

int Rezept::count( )
{
  return m_rez.size();  
}

void Rezept::readFile( )
{
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  fp = fopen(m_fileName.c_str(), "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);
  while ((read = getline(&line, &len, fp)) != -1) {
    //printf("Retrieved line of length %zu :\n", read);
    printf("%s", line);
    //char myString[] = "The quick brown fox";
    char *p = strtok(line, " ");
    int i = 0; 
    while (p) {
      printf ("Token: %s\n", p);
      if (i == 0) m_step.bez = p;
      if (i == 1) m_step.temp = atof(p);
      if (i == 2) m_step.zeit = atoi(p);
      
      i++;
      p = strtok(NULL, " ");
    } 
    m_rez.push_back (m_step);
  }
}

void Rezept::printRezept()
{
  for (unsigned i=0; i < m_rez.size(); i++)
    cout << "bez: " << m_rez.at(i).bez << " Temp: " << m_rez.at(i).temp << " Zeit: " << m_rez.at(i).zeit << "\n";
}

int main(int argc, char *argv[]) 
{ 
    Rezept cx("rezept.txt");
    cx.printRezept();

    return 0; 
} 

