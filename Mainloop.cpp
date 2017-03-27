/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: The codes to call the appropretiate command functions. If return false, program terminates.
***************************************************************/

#include "Mainloop.h"
#include "Command.h"
#include "Task.h"
#include <iostream>
#include "Linkedlist.hxx"
#include "SortedLinkedList.hxx"
#include "colortext.h"

bool mainloop(std::string command, SortedLinkedList<Task> &inventory, SortedLinkedList<Task> &cominventory) {		//This is the main program loop, when return false, program will terminate
  if (command == "add" or command == "ADD" or command == "Add") {
    Task* a = add();         
    inventory.push_in(a); 
    return true;
  }
  if (command == "print" or command == "PRINT" or command == "Print") {
    print(inventory);
    return true;
  }
  if (command == "detailed" or command == "DETAILED" or command == "Detailed") {
    detailed(inventory);
    return true;
  }
  if (command == "remove" or command == "REMOVE" or command == "Remove") {
    remove(inventory);    
    return true;
  }
  if (command == "complete" or command == "COMPLETE" or command == "Complete") {
    complete(inventory, cominventory);
    return true;
  }
  if (command == "completed" or command == "COMPLETED" or command == "Completed") {
    completed(cominventory);
    return true;
  }
  if (command == "save" or command == "SAVE" or command == "Save") {
    save(inventory);
    return true;
  }
  if (command == "load" or command == "LOAD" or command == "Load") {
    load(inventory);
    return true;
  }
  if (command == "exit" or command == "EXIT" or command == "Exit") {
    exit();
    return false;
  }
  if (command == "help" or command == "HELP" or command == "Help") {
    help();
    return true;
  }
  
  std::cout <<BOLDWHITE<< "This command "<<RESET<<BOLDRED<<"doesn't exist"<<RESET<<BOLDWHITE<<" -> '" << command << "'"<<RESET<<GREEN<<"  			(ʃ_⌣̀ )" <<RESET<< std::endl;
  return true;
}


