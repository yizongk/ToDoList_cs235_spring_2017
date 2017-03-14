#include "Mainloop.h"
#include "Command.h"
#include "Task.h"
#include <iostream>
#include "Linkedlist.hxx"
#include "SortedLinkedList.hxx"

bool mainloop(std::string command, SortedLinkedList<Task> &inventory, SortedLinkedList<Task> &cominventory) {
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

  std::cout << "This command doesn't exist -> '" << command << "'  			(ʃ_⌣̀ )" << std::endl;
  return true;
}


