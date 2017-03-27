/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: Codes for the header file of mainloop, for easier linking
***************************************************************/

#ifndef MAINLOOP_H
#define MAINLOOP_H

#include <string>
#include "Task.h"
#include "Linkedlist.hxx"
#include "SortedLinkedList.hxx"

bool mainloop(std::string a, SortedLinkedList<Task> &inventory, SortedLinkedList<Task> &cominventory);

#endif 
