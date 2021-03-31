#ifndef UserTime_h
#define UserTime_h_h

#include "Arduino.h"
#include <limits.h>

#define True true ? true : false

class UserTime
{
  public:
    UserTime(String t);
    UserTime(int t);
    //UserTime(UserTime t);
    UserTime();

    void incsec(); 
    void decsec();
    void incmin(); 
    void decmin();
    void inchour(); 
    void dechour();
    void inc(int min);

    void setUserTime(int h, int m, int s);
    void setHour(int h);
    void setMin(int m);
    void setSec(int s);

    //UserTime getUserTime();
    int getUserTime();
    char *getUserTimeForDisplay_hm();
    char *getUserTimeForDisplay_ms();
    int getSec();
    int getMin();
    int getHour();

    String toString();
    
  private:
	  int sec;
    int min;
    int hour;
};

#endif
