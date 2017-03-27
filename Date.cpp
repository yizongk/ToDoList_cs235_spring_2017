/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: Definition for the class Date
***************************************************************/

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

int Date::difference() {			//return the rough estimate of the total day count converted from months and years.
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

int Date::returnInt(char a) {			//return the ascii code for a character
  int temp = a - '0';  
  return temp;
}

void Date::stringToInt(std::string a) {		//return a properly formated Date object from a line of properly formated text.
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

int Date::returnNumOfDigits(int a) const {		//will return the number of digits to assite in constructing a properly formated Date object.
  if (a < 0) {
    return 0;
  }

  int numofdigits = 1;
  for (int i = 1; a/i >= 10; i *= 10) {			//will checks for number of digits
    ++numofdigits; 
  }
  
  return numofdigits;
}

std::string Date::intToString(int a) const {		//converts intergers into strings, 45 will be "45"
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
