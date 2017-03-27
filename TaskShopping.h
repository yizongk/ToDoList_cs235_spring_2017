/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: Codes for the class Task Shopping, which inherites from generic task, has a linklist variable to store the list of item to be shopped.
***************************************************************/

#ifndef TASK_SHOPPING_H
#define TASK_SHOPPING_H

#include <vector>
#include <string>
#include "Linkedlist.hxx"

class ShoppingTask : public Task {
 public:
  ShoppingTask();
  ShoppingTask(Task a);
  ~ShoppingTask();

  friend std::ostream& operator<<(std::ostream& a, const ShoppingTask& rhs); 

  void add_list(std::string* a);
  void input_from_line(std::string line);

  std::string type() const;
  Date dueDate() const;  
  std::string description() const;
  node<std::string>* getlisthead();

 private:
  std::string _type;
  Date _dueDate;
  std::string _description;

  Linklist<std::string> _shoplist;		
};


#endif
