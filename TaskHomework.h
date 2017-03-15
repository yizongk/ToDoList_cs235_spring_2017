#ifndef TASKHOMEWORK_H
#define TASKHOMEWORK_H
#include "Task.h"
#include <iostream>

class HomeworkTask : public Task {
 public:
  HomeworkTask(Task a);
  HomeworkTask();

  friend std::ostream& operator<<(std::ostream& a, const HomeworkTask& rhs); 

  std::string type() const;
  Date dueDate() const;  
  std::string description() const;
  void print();
  std::string subject(); 
  void input_from_line(std::string line);

  void set_subject(std::string a);

 private:
  std::string _type;
  Date _dueDate;
  std::string _description;

  std::string _subject;
};


#endif
