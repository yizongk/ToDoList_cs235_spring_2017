/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: Codes for linkedlist class, uses nodes as the storage unit
***************************************************************/

#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include <cstddef>
#include "Task.h"
#include "Node.hxx"
#include "colortext.h"

template <typename T> class Linklist;
template <typename T> std::ostream& operator<<(std::ostream&, const Linklist<T>&);


template <typename T>
class Linklist {
 public:
  Linklist();
  ~Linklist();

  friend std::ostream& operator<< <T>(std::ostream& a, const Linklist<T>& rhs);

  node<T>* create_node(T* a);
  node<T>* get_head();
  void push_front(T* a);
  void insert(node<T>* a, unsigned int position);
  void remove(unsigned int position);		
  unsigned int list_count() const;
  void print(bool detailed) const;
  node<T>* get_node(int i);
  void transfer(Linklist<T>& targetlist, int i, unsigned int sortedindex);
  node<T>** get_head_ptr();
  void count_minus_one();
  void clear();

 private:
  node<T>* _head;
  unsigned int _list_count;
};


template <typename T> Linklist<T>::Linklist() {
  _head = NULL;
  _list_count = 0;
}

template <typename T> Linklist<T>::~Linklist() {
  delete _head;
}

template <typename T> std::ostream& operator<<(std::ostream& a, const Linklist<T>& rhs) {
  if (rhs._head == NULL) {
    a << "This list is empty";
    return a;
  }

  a << *rhs._head;
  return a;
}


template <typename T> void Linklist<T>::push_front(T* a) {  //push in front, and push rest of list back.
  node<T>* temp = new node<T>;
  temp->data = a;
  temp->p_next = _head;
  _head = temp;
  _list_count++;
}

template <typename T> node<T>* Linklist<T>::create_node(T* a) {
  node<T>* temp = new node<T>;
  temp->data = a;  			//maybe here since temp->data is alrdy allocated new string, it just copy the value instead of point to what a points to.
  temp->p_next = NULL;
  return temp;
}

template <typename T> node<T>* Linklist<T>::get_head() {
  return _head;
}

//insert into a list with the provided index
template <typename T> void Linklist<T>::insert(node<T>* a, unsigned int position) {	//itr is always one node ahead of itr_pre, this fct starts count from 0
  if (_list_count == 0) {
    _head = a;
    _list_count++;
    return;
  }

  if (position > _list_count) {
    std::cout<<BOLDYELLOW<<"possition exceed what's availiable in the list. You are trying to insert "<< position << " into " << _list_count <<RESET<<std::endl;
    return;
  } 

  if (position == 0) {
    a->p_next = _head;				//fct breaks down at position one, this is to combat that.
    _head = a;
    _list_count++;
    return;
  }

  node<T>* itr = _head;
  node<T>* itr_pre;  

  for (unsigned int i = 0; i <= _list_count; i++) {	
    if (i == _list_count) {
      itr->p_next = a;
      a->p_next = NULL;
      break;
    }

    if (i == position) {  
      a->p_next = itr;  
      itr_pre->p_next = a;
      break;
    }
    
    if (i != _list_count - 1) {			//prevent from accessing unallocated memoery during a situation of inserting at the last spot on the link list.
      itr_pre = itr;
      itr = itr->p_next;
    }
  }

  _list_count++;
  itr = NULL;
  itr_pre = NULL;
  return;
}

template <typename T> void Linklist<T>::remove(unsigned int position) {//removes a node from the linklist with the provided index
  --position;				//I designed this part to work with counting from 0. So must decrement by one from the user's point of view.

  if (_list_count == 0) {
    std::cout<<BOLDWHITE<<"List is empty, nothing to remove."<<RESET<<std::endl;
    return;
  }

  if (position >= _list_count) {
    std::cout<<BOLDWHITE<<"no such position"<<RESET<<std::endl;
    return;
  }
  
  node<T>* itr = _head;
  node<T>* itr_pre; 

  if (position == 0) {
    _head = _head->p_next;    

    itr->p_next = NULL;			//HAVE TO POINT TO NULL< OTHERWISE IT WILL CALL DESTUCTOR ON NODE LINKLIST RECURSIVLY
    delete itr;
    _list_count--;
    return;
  } 

  for (unsigned int i = 0; i < _list_count; i++) {
    if (i == position) {  
      if(itr->p_next != NULL) {
        itr_pre->p_next = itr->p_next;			
      }							
      else {
        itr_pre->p_next = NULL;				//since its at end of list anyway, set itr_pre->p_next to NULL
      }

      itr->p_next = NULL;
      delete itr;
      break;
    }

    itr_pre = itr;        
    itr = itr->p_next;
  }  

  _list_count--;
  itr = NULL;
  itr_pre = NULL;
  return;
}

template <typename T> unsigned int Linklist<T>::list_count() const {		//return the number of node in the linklist
  return _list_count;
}

template <typename T> void Linklist<T>::print(bool detailed) const {		//false means print, true means detailed print
  int i = 1;

  node<T>* itr = _head; 
  while(itr != NULL) {
    std::cout << i << ". ";
    itr->print(detailed);
    std::cout<<std::endl;

    ++i;
    itr = itr->p_next;
  }
}

template <typename T> node<T>* Linklist<T>::get_node(int i) {	//return node at the index provided
  node<T>* itr = _head;

  for (int counter = 1; counter < i; ++counter) {    		//at i = 1, this wornt run and will return itr, which is the where _head points to.
    itr = itr->p_next;
  }

  return itr;
}

template <typename T> void Linklist<T>::transfer(Linklist<T>& targetlist, int i, unsigned int sortedindex) {	//the overhead fct that call this function makes sure 
														//that int i, is not less than 1, or greater than list_count.
  node<T>* itr = this->get_node(i);										//sortedindex is determine by fct that calls it.

  if (i == 1) {
    this->_head = _head->p_next;
    itr->p_next = NULL;   			//reset its pointing to null, to disconnectd from inventory list
    targetlist.insert(itr, sortedindex);
    return;
  }

  if (i == this->list_count()) {
    node<T>* itrpre = this->get_node(i-1);		//get the node right before it. this is safe, becasue at this point in the fct, we can confirm list_count is greater than 1.
    itrpre->p_next = NULL;
    targetlist.insert(itr, sortedindex);
    return; 
  }

  node<T>* itrpre = this->get_node(i-1);
  itrpre->p_next = itr->p_next;
  itr->p_next = NULL; 				//reset the node to point to NULL, to disconnect from original list
  targetlist.insert(itr, sortedindex);
  return;
} 

template <typename T> node<T>** Linklist<T>::get_head_ptr() {		//return the address of the pointer so we may change it to point to something else.
  return &_head;
}

template <typename T> void Linklist<T>::count_minus_one() {		//for decrementing the list count, used when removing a node from the list
  --_list_count;
}

template <typename T> void Linklist<T>::clear() {			//Cleans the linklist, by deleting all dynamically allocated memory.
  _list_count = 0;
  node<T>* itr = _head;
  _head = NULL;

  delete itr;
}


#endif
