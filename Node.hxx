/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: Codes for the storage unit to be used in a linklist, uses pointer as the storage, because of the need to type_case later on.
***************************************************************/

#ifndef NODE_H
#define NODE_H
#include <iostream>


template <typename T> 
struct node {
  ~node();

  void print(bool detailed) ;

  T* data = NULL;  
  node<T>* p_next = NULL;
};

template <typename T>std::ostream& operator<<(std::ostream& a, const node<T>& rhs) {
  const node<T>* itr = &rhs;  
  while (itr != NULL) {
    T* tempdata = itr->data;
    a << "    ➢ " <<*tempdata << std::endl;

    itr = itr->p_next;
  }

  return a;
}

template <typename T> node<T>::~node() {
  delete data;
  delete p_next;
}

template <typename T> void node<T>::print(bool detailed) {		//false means print, true means detailed print
  if(detailed == true) {
    std::cout<<*data; 
  } else {
    data->print();
  }
}


#endif


