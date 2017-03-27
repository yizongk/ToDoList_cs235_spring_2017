/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: Codes for the class Date, which will be present in all task as a way for sorting.
***************************************************************/

#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>

class Date {
 public:
  Date();
  Date(int m, int d, int y); 

  int day() const;
  int month() const;
  int year() const;
  int difference();
  void print();

  friend std::ostream& operator<<(std::ostream& a, const Date& rhs); 

  void set_day(int d);
  void set_month(int m);
  void set_year(int y);

  int returnInt(char a);
  void stringToInt(std::string a);
  int returnNumOfDigits(int a) const;
  std::string intToString(int a) const;

 private:
  int _day;
  int _month;
  int _year;
};

#endif 
