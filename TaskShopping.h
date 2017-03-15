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
