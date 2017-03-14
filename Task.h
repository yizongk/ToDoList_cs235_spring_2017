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
  
  virtual std::string status() const;
  virtual std::string type() const;
  virtual Date dueDate() const;  
  virtual std::string description() const;
  virtual void input_from_line(std::string line);
  void print();
  
  void setStatus(std::string a);
  void setType(std::string a);
  void setDueDate(Date a);
  void setDescription(std::string a);

 private:
  std::string _status;  
  std::string _type;
  Date _dueDate;
  std::string _description;
};

#endif
