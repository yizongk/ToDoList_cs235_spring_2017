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
