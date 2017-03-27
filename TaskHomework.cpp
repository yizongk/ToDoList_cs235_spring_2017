/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: Codes for the definition of class Task Homework
***************************************************************/

#include "TaskHomework.h"
#include <iostream>


HomeworkTask::HomeworkTask(Task a) {
  _type = a.type();
  _dueDate = a.dueDate();
  _description = a.description(); 

}

HomeworkTask::HomeworkTask() {

}

std::ostream& operator<<(std::ostream& a, const HomeworkTask& rhs) {		

  a << rhs._dueDate << " - [" << rhs._type << "] 	" << rhs._description << " -> "<< std::endl; 
  a << "    SUBJECT: 	" << rhs._subject << std::endl;
  
  return a;
}

std::string HomeworkTask::type() const {
  return _type;
}

Date HomeworkTask::dueDate() const {
  return _dueDate;
}
 
std::string HomeworkTask::description() const {
  return _description;
}

void HomeworkTask::print() {
  std::cout << _dueDate << " - [" << _type << "] " << _description << " -> "<< std::endl; 
  std::cout << "   SUBJECT: 	" << _subject ;
}

std::string HomeworkTask::subject() {
  return _subject;
}

void HomeworkTask::input_from_line(std::string line) {		//Constructs a proper Homework object from a single line of text from text-input-file
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
        _type = "Homework";
   
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
            //fill out subject
        _subject = data;
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

void HomeworkTask::set_subject(std::string a) {
  _subject = a;
}

