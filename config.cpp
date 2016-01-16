/****************************************************************
Datei     : config.cpp
Author    : Oed
Datum     : 08.01.2016
Parameter :         
Return    : 
Aufgabe   : Test der Kalsse config.cpp
Comp.     : c++ config.cpp -o config
****************************************************************/
#include "config.h"

Config::Config( string fileName ) 
{ 
  cout << "Konstruktor von 'Config'\n"; 
  m_fileName = fileName;
} 

Config::~Config() 
{ 
  cout << "Destruktor von 'Config'\n"; 
} 

void Config::setFileName( string fileName ) 
{ 
  m_fileName = fileName;
} 

string Config::getFileName() 
{ 
  return m_fileName; 
} 


string Config::getValue( string suchKey )
{
  string line;
  ifstream input(m_fileName.c_str());
 
  if (!input)
  {
    std::cerr << "Datei beim Oeffnen der Datei " << m_fileName << "\n";
    return " ";
  }
  
  while (getline(input, line))
  {
    //cout << line << '\n';
    string key = line.substr(0, line.find("="));
    string val = line.substr(line.find("=") + 1);
    cout << "Line: " << line << " key: " << key << " val:" << val << "\n";
    if ( key == suchKey )
    {
      return val;
    }
  } 
  return " ";  
}

/*
int main(int argc, char *argv[]) 
{ 
    Config *cf = new Config("config.txt"); 
    Config cx("config.txt");

    cout << "FileName: " << cf->getFileName() << "\n"; 
    cout << "return(port1): " << cf->getValue("port1") << "\n";
    cout << "return(port2): " << cf->getValue("port2") << "\n";
    
    cout << "\nFileName CX: " << cx.getFileName() << "\n";

    delete cf; 

    return 0; 
} 
*/
