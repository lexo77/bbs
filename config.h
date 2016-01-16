#include <iostream> 
#include <string>
#include <fstream>
using namespace std;

class Config   
{ 
public: 
    Config( string ); 
    ~Config( ); 
    void setFileName( string ); 
    string getFileName( ); 
    string getValue( string );
        
private: 
    string m_fileName;
}; 
