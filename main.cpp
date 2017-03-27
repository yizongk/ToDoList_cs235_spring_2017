/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: The main loop of the program, will take in user command here
***************************************************************/

#include <iostream>
#include "Task.h"
#include <string>
#include "Mainloop.h"
#include "Linkedlist.hxx"
#include "SortedLinkedList.hxx"
#include "colortext.h"

using namespace std;

int main() {							//takes in a command, which then starts the main loop
  cout <<GREEN<< "◤━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◥" <<RESET<< endl;
  cout <<BOLDGREEN<< "◖ › Welcome, to the OxygenTask ‹  ◗" <<RESET<< endl;
  cout <<GREEN<< "◣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◢" <<RESET<< endl;

  SortedLinkedList<Task> inventory;
  SortedLinkedList<Task> cominventory;
  string command;
  bool status;
 
  cout << BOLDGREEN << "Waiting for command...(you can type 'help') ➤  "<<RESET ;	//this small chuck of code here is for visual purposes, could have been in the while loop that's right after it.
  getline(cin, command);
  cout << endl;
  status = mainloop(command, inventory, cominventory);

  while (status == true) {
    cout << endl;
    cout <<GREEN<< "⬤  ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ●  ⬤" <<RESET<< endl;
    cout <<BOLDGREEN<< "Waiting for command... ➤  " <<RESET;
    getline(cin, command);
    cout << endl;
    status = mainloop(command, inventory, cominventory);
  }

  return 0;
}
