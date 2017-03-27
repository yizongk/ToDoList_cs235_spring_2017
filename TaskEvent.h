/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: Codes for the class Task Event, which inherites from generic Task, has a few extra string variable to store task specific information.
***************************************************************/

#ifndef TASKEVENT_H
#define TASKEVENT_H
#include "Task.h"
#include <iostream>

class EventTask : public Task {
 public:
  EventTask();
  EventTask(Task a);
  ~EventTask();

  std::string type() const;
  Date dueDate() const;  
  std::string description() const;
  void print();
  std::string location();
  std::string time();
  void input_from_line(std::string line);

  void set_location(std::string a);
  void set_time(std::string a);

  friend std::ostream& operator<<(std::ostream& a, const EventTask& rhs);

 private:
  std::string _type;
  Date _dueDate;
  std::string _description;

  std::string _location;
  std::string _time;
};

#endif
