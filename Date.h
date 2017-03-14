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
