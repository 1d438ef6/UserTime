#include "UserTime.h"

/**
 * Erstellt den Datentyp UserTime aus String
 * möglich:
 * -hhmm      -> s = 0
 * -hh:mm     -> s = 0
 * -hhmmss
 * -hh:mm:ss
 */
UserTime::UserTime(String t){
  if(t.length() == 4){
    this -> hour = t.substring(0, 2).toInt();
    this -> min = t.substring(2).toInt();
    this -> sec = 0;
  } else if(t.length() == 5){
    this -> hour = t.substring(0, 2).toInt();
    this -> min = t.substring(3).toInt();
    this -> sec = 0;
  } else if(t.length() == 6){
    this -> hour = t.substring(0, 2).toInt();
    this -> min = t.substring(2, 4).toInt();
    this -> sec = t.substring(4).toInt();
  } else if(t.length() == 8){
    this -> hour = t.substring(0, 2).toInt();
    this -> min = t.substring(3, 5).toInt();
    this -> sec = t.substring(6).toInt();
  } else {
    this -> hour = 0;
    this -> min = 0;
    this -> sec = 0;
  }
}

/**
 * Erstellt den Datentyp UserTime aus Integer
 * -hhmmss
 */
UserTime::UserTime(int t){
  if(t >= 100000){
    this -> hour = t/10000;
    this -> min = (t % 10000)/100;
    this -> sec = t % 100;
  } else {
    this -> hour = 0;
    this -> min = 0;
    this -> sec = 0;
  }
}

/**
 * h = 0
 * m = 0
 * s = 0
 */
UserTime::UserTime(){
  this -> hour = 0;
  this -> min = 0;
  this -> sec = 0;
}

/**
 * inccrease sec
 */
void UserTime::incsec(){
  this -> sec++;
  if(this -> sec >= 60){
    this -> sec = 0;
    incmin();
  }
}

/**
 * decrease sec
 */
void UserTime::decsec(){
  this -> sec--;
  if(this -> sec < 0){
    this -> sec = 59;
    decmin();
  }
}

/**
 * increase min
 */
void UserTime::incmin(){
  this -> min++;
  if(this -> min >= 60){
    this -> min = 0;
    inchour();
  }
}

/**
 * decrease min
 */
void UserTime::decmin(){
  this -> min--;
  if(this -> min < 0){
    this -> min = 59;
    dechour();
  }
}

/**
 * increase hour
 */
void UserTime::inchour(){
  this -> hour++;
  if(this -> hour >= 24){
    this -> hour = 0; 
  }
}

/**
 * decrease hour
 */
void UserTime::dechour(){
  this -> hour--;
  if(this -> hour < 0){
    this -> hour = 23;
  }
}

/**
 * change UserTime
 * hour = h
 * min = m
 * sec = s
 */
void UserTime::setUserTime(int h, int m, int s){
  this -> hour = h;
  this -> min = m;
  this -> sec = s;
}

/**
 * set hour to h
 */
void UserTime::setHour(int h){
   this -> hour = h;
}

/**
 * set min to m
 */
void UserTime::setMin(int m){
  this -> min = m;
}

/**
 * set sec to s
 */
void UserTime::setSec(int s){
  this -> sec = s;
}

/**
 * return UserTime as integer
 */
int UserTime::getUserTime(){
  return (this -> hour * 10000) + (this -> min * 100) + (this -> sec);
}

/**
 * return hour and min for a 7 segment display
 * hhmm
 */
char *UserTime::getUserTimeForDisplay_hm(){
  static char ret[4];
  if(this -> hour < 10){
    ret[0] = '0';
    ret[1] = this -> hour + '0';
  } else {
    ret[0] = this -> hour / 10 + '0';
    ret[1] = this -> hour % 10 + '0';
  }
  if(this -> min < 10){
    ret[2] = '0';
    ret[3] = this -> min + '0';
  } else {
    ret[2] = this -> min / 10 + '0';
    ret[3] = this -> min % 10 + '0';
  }
  return ret;
}

/**
 * return min and sec for a 7 segment display
 * mmss
 */
char *UserTime::getUserTimeForDisplay_ms(){
  static char ret[4];
  if(this -> min < 10){
    ret[0] = '0';
    ret[1] = this -> min + '0';
  } else {
    ret[0] = this -> min / 10 + '0';
    ret[1] = this -> min % 10 + '0';
  }
  if(this -> sec < 10){
    ret[2] = '0';
    ret[3] = this -> sec + '0';
  } else {
    ret[2] = this -> sec / 10 + '0';
    ret[3] = this -> sec % 10 + '0';
  }
  return ret;
}

/**
 * return hour as integer
 */
int UserTime::getHour(){
  return this -> hour;
}

/**
 * return min as integer
 */
int UserTime::getMin(){
  return this -> min;
}

/**
 * return sec as integer
 */
int UserTime::getSec(){
  return this -> sec;
}

/**
 * return UserTime as string
 * hh:mm:ss
 */
String UserTime::toString(){
  //String ret = String(this -> hour) + ":" + String(this -> min) + ":" + String(this -> sec);
  String ret = (this -> hour > 9 ? String(this -> hour) : '0' + String(this -> hour)) + ":"
               + (this -> min > 9 ? String(this -> min) : '0' + String(this -> min)) + ":"
               + (this -> sec > 9 ? String(this -> sec) : '0' + String(this -> sec));
  return ret;
}
