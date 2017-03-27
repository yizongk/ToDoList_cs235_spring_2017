/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: Codes for the parent class of the all the different type of task we will be saving
***************************************************************/

#ifndef TASK_H
#define TASK_H
#include "Date.h"
#include <iostream>
#include <string>

class Task {
 public:
  Task();
  Task(std::string name);
  Task(const Task& a);
  virtual ~Task(); 
  friend std::ostream& operator<<(std::ostream& a, const Task& rhs);
  
  virtual std::string type() const;
  virtual Date dueDate() const;  
  virtual std::string description() const;
  virtual void input_from_line(std::string line);
  void print();
  
  void setType(std::string a);
  void setDueDate(Date a);
  void setDescription(std::string a);

 private:
  std::string _type;
  Date _dueDate;
  std::string _description;
};

#endif
