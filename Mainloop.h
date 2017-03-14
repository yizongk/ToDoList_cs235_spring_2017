#ifndef MAINLOOP_H
#define MAINLOOP_H

#include <string>
#include "Task.h"
#include "Linkedlist.hxx"
#include "SortedLinkedList.hxx"

bool mainloop(std::string a, SortedLinkedList<Task> &inventory, SortedLinkedList<Task> &cominventory);

#endif 
