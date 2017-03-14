#include <iostream>
#include "Task.h"
#include <string>
#include "Mainloop.h"
#include "Linkedlist.hxx"
#include "SortedLinkedList.hxx"

using namespace std;

int main() {
  cout << "◤━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◥" << endl;
  cout << "◖ › Welcome, to the OxygenTask ‹  ◗" << endl;
  cout << "◣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◢" << endl;

  SortedLinkedList<Task> inventory;
  SortedLinkedList<Task> cominventory;
  string command;
  bool status;
 
  cout << "Waiting for command...(you can type 'help') ➤  " ;	//this small chuck of code here is for visual purposes, could have been in the while loop that's right after it.
  getline(cin, command);
  cout << endl;
  status = mainloop(command, inventory, cominventory);

  while (status == true) {
    cout << endl;
    cout << "⬤  ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ●  ⬤" << endl;
    cout << "Waiting for command... ➤  " ;
    getline(cin, command);
    cout << endl;
    status = mainloop(command, inventory, cominventory);
  }

  return 0;
}
