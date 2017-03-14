#include "TaskShopping.h"
#include <iostream>

ShoppingTask::ShoppingTask(Task a) {
  _status = a.status(); 
  _type = a.type();
  _dueDate = a.dueDate();
  _description = a.description(); 

}

ShoppingTask::ShoppingTask() {

}

ShoppingTask::~ShoppingTask() {

}

std::ostream& operator<<(std::ostream& a, const ShoppingTask& rhs) {		

  a << rhs._dueDate << " - [" << rhs._type << "] 	" << rhs._description << " -> "<< std::endl; 

  a<<"    ITEMS TO PURCHASE: "<<std::endl;

  if (rhs._shoplist.list_count() == 0) {
    a<<"    Nothing in this list";
  } else {
    a<<rhs._shoplist;
  }
  
  return a;
}

void ShoppingTask::add_list(std::string* a) {
  _shoplist.push_front(a);
}

void ShoppingTask::input_from_line(std::string line) {
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
        _type = "Shopping";
   
      } else if (counter == 1) {
            //fill out date
        ++counter;
        Date rdydate;
        rdydate.stringToInt(data);			//codes to construct Data object from file input
        _dueDate = rdydate;            
  
      } else if (counter == 2) {
            //fill out description
        ++counter;
        _description = data;
      } else {
           //fill out shop list
        std::string* a = new std::string;
        *a = data;
        _shoplist.push_front(a);
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

std::string ShoppingTask::status() const {
  return _status;
}

std::string ShoppingTask::type() const {
  return _type;
}

Date ShoppingTask::dueDate() const {
  return _dueDate;
}
 
std::string ShoppingTask::description() const {
  return _description;
}

node<std::string>* ShoppingTask::getlisthead() {
  return _shoplist.get_node(1);;
}


