#include "Date.h"

Date::Date() {
  _day = 0;    
  _month = 0;
  _year = 0;
}

Date::Date(int m, int d, int y) {
  _day = d;		
  _month = m;
  _year = y;
}

int Date::day() const {
  return _day;
}

int Date::month () const {
  return _month;
}

int Date::year() const {
  return _year;
}

int Date::difference() {
  int temp;
  temp = day();
  temp = temp + ( 30 * month() );		//convert month to day count
  temp = temp + ( 360 * year() );		//couvert year to day count.
  return temp;
}

void Date::print() {
  std::cout<<month()<<"/"<<day()<<"/"<<year();
}

std::ostream& operator<<(std::ostream& a, const Date& rhs) {
  std::string month, day, year;
  month = rhs.intToString( rhs.month() );
  day   = rhs.intToString( rhs.day()   );
  year  = rhs.intToString( rhs.year()  );

  a << month << "/" << day << "/" << year;
  return a;
}

void Date::set_day(int d) {
  _day = d; 
}

void Date::set_month(int m) {
  _month = m;
}

void Date::set_year(int y) {
  _year = y;
}

int Date::returnInt(char a) {
  int temp = a - '0';
  return temp;
}

void Date::stringToInt(std::string a) {
  int month;
  month = returnInt(a[0]) * 10;
  month = month + returnInt(a[1]);
  _month = month;

  int day;
  day = returnInt(a[3]) * 10;
  day = day + returnInt(a[4]);
  _day = day;

  int year;
  year = returnInt(a[6]) * 1000; 
  year = year + returnInt(a[7]) * 100;
  year = year + returnInt(a[8]) * 10;
  year = year + returnInt(a[9]);
  _year = year;
}

int Date::returnNumOfDigits(int a) const {
  if (a < 0) {
    return 0;
  }

  int numofdigits = 1;
  for (int i = 1; a/i > 10; i *= 10) {			//will checks for number of digits
    ++numofdigits; 
  }
  
  return numofdigits;
}

std::string Date::intToString(int a) const {
  std::string stringvalue = "";
  int numberofdigits = returnNumOfDigits(a);
  if (numberofdigits == 0) {
    return "Int-String conversion failed, number less than zero";
  }
 
  if (numberofdigits == 1) {
    stringvalue.push_back( '0'     );
    stringvalue.push_back( a + '0' );
    return stringvalue;
  } 
  else if (numberofdigits == 2) {				//only three case possible in this Date object senario, 1 digit for date less than 10, 2 digits, 
    stringvalue.push_back( (a/10) + '0' );					//and 4 digits for year format. 
    stringvalue.push_back( (a%10) + '0' );
    return stringvalue;
  } else {						//else the int a must be a 4 digit number. which is the year format
    stringvalue.push_back( (a/1000) + '0'          );
    stringvalue.push_back( (a%1000)/100 + '0'      );
    stringvalue.push_back( ((a%1000)%100)/10 + '0' );
    stringvalue.push_back( ((a%1000)%100)%10 + '0' );
    return stringvalue;
  }

  return "Int-Strig conversion failed, number more than 4 digits";
}
