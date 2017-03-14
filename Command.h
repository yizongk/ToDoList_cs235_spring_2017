#ifndef COMMAND_H
#define COMMAND_H

#include "Linkedlist.hxx"

Task* add();						//done
void print(SortedLinkedList<Task> &inventory);		//done
void detailed(SortedLinkedList<Task> &inventory);	//done
void remove(SortedLinkedList<Task> &inventory);		//done
void complete(SortedLinkedList<Task> &source, SortedLinkedList<Task> &target);	//done
void completed(SortedLinkedList<Task> &cominventory);	//done
void save(SortedLinkedList<Task>& inventory);		//done? got to do a few more test
void load(SortedLinkedList<Task>& inventory);         	//done
void exit();						//done
void help();						//done

#endif

