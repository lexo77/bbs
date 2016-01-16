#include <fstream>
#include <iostream> 
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Rezept   
{ 
public: 
    Rezept( string ); 
    ~Rezept( ); 
    string getBez(int);
    double getTemp(int);
    int getZeit(int);
    void printRezept();
    int count();
private: 
    
    void readFile();
    string m_fileName;
    struct step {
      string bez;
      double temp;
      int zeit;
    } m_step;
    vector<step> m_rez;       

    
}; 
