#include "TaskEvent.h"
#include <iostream>



EventTask::EventTask() {
  _type = "";
  _description = "";
}

EventTask::EventTask(Task a) {
  _type = a.type();
  _dueDate = a.dueDate();
  _description = a.description(); 

}

EventTask::~EventTask() {

}

std::ostream& operator<<(std::ostream& a, const EventTask& rhs) {

  a << rhs._dueDate << " - [" << rhs._type << "] 	" << rhs._description << " -> "<< std::endl; 
  a << "    WHERE: 	" << rhs._location << std::endl;
  a << "    WHEN:  	" << rhs._time << std::endl;

  return a;

}

std::string EventTask::type() const {
  return _type;
}

Date EventTask::dueDate() const {
  return _dueDate;
}
 
std::string EventTask::description() const {
  return _description;
}

void EventTask::print() {
  std::cout << _dueDate << " - [" << _type << "] " << _description << " -> "<< std::endl; 
  std::cout << "   WHERE: 	" << _location << std::endl;
  std::cout << "   WHEN:  	" << _time ;

}

std::string EventTask::location() {
  return _location;
}

std::string EventTask::time() {
  return _time;
}

void EventTask::input_from_line(std::string line) {
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
        _type = "Event";
   
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
      } else if (counter == 3) {
            //fill out location
        ++counter;
        _location = data;
      } else {
            //fill out time
        _time = data;
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

void EventTask::set_location(std::string a) {
  _location = a;
}

void EventTask::set_time(std::string a) {
  _time = a;
}
