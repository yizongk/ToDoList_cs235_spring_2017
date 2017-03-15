#include "Task.h"
#include "TaskShopping.h"
#include "TaskEvent.h"
#include "TaskHomework.h"

Task::Task() {
  _type = "Generic";
  Date _dueDate; 		
  _description = "Default Task, no description avaliable.";
}

Task::Task(std::string des) 
    : _dueDate(1,2,3) {
  _type = "Generic";
  _description = des;
}

Task::Task(const Task& rhs) {
  _type = rhs._type;
  _description = rhs._description;
  _dueDate = rhs._dueDate;
}

Task::~Task() {

}

std::ostream& operator<<(std::ostream& a, const Task& rhs) {

  if (rhs.type() == "Shopping") {
    const Task* base = &rhs;
    const ShoppingTask* derived = dynamic_cast<const ShoppingTask*>(base);
    a << *derived;
    return a;
  } 

  if (rhs.type() == "Event") {
    const Task* base = &rhs;
    const EventTask* derived = dynamic_cast<const EventTask*>(base);
    a << *derived;
    return a;
  }

  if (rhs.type() == "Homework") {
    const Task* base = &rhs;
    const HomeworkTask* derived = dynamic_cast<const HomeworkTask*>(base);
    a<< *derived; 
    return a;
  }

  a << rhs.dueDate() << " - [" << rhs.type() << "] 	" << rhs.description() << " -> "; 
  return a;
}

std::string Task::type() const {
  return _type;
}

Date Task::dueDate() const {
  return _dueDate;
}

std::string Task::description() const {
  return _description;
}

void Task::input_from_line(std::string line) {
  std::string data = "";
  int counter = 0;
  while(line.size() != 0) {
    if (line[0] == '|' or line.size() == 1) {  //since in input file, there's no '|' at the end, must have extra condition to account for that.	
          //fix the end case of the last char
      if (line.size() == 1) {
        data += line[0];  
      }
	
          //codes to fill the member
      if (counter == 0) {
            //fill out type
        ++counter;
        _type = "Generic";
   
      } else if (counter == 1) {
            //fill out date
        ++counter;
        Date rdydate;
        rdydate.stringToInt(data);			//codes to construct Data object from file input
        _dueDate = rdydate;            
  
      } else {
            //fill out description
        _description = data;
      }

          //reseting some variable
      line.erase(line.begin());
      data = "";

    } else {
      data += line[0];  
      line.erase(line.begin());
    }
  }
}

void Task::setType(std::string a) {
  _type = a;
}

void Task::setDueDate(Date a) {
  _dueDate = a;
}
  
void Task::setDescription(std::string a) {
  _description = a;
}

void Task::print() {
  std::cout<< dueDate() << " - [" << type() << "] 	" << description() << " -> "; 
}

