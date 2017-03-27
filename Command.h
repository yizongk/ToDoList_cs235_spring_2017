/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: Codes for the header file of commands to be used by user, to allow for easier linking
***************************************************************/

#ifndef COMMAND_H
#define COMMAND_H

#include "Linkedlist.hxx"

Task* add();						//done
void print(SortedLinkedList<Task> &inventory);		//done
void detailed(SortedLinkedList<Task> &inventory);	//done
void remove(SortedLinkedList<Task> &inventory);		//done
void complete(SortedLinkedList<Task> &source, SortedLinkedList<Task> &target);	//done
void completed(SortedLinkedList<Task> &cominventory);	//done
void save(SortedLinkedList<Task>& inventory);		//done
void load(SortedLinkedList<Task>& inventory);         	//done
void exit();						//done
void help();						//done

#endif

