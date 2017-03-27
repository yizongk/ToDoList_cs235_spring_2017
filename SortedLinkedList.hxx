/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: Codes a sorted link list, which is a wrapper around a link list, but will find the right place to insert into the list so that it's sorted by date then alphebet
***************************************************************/

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include "Linkedlist.hxx"
#include "Task.h"
#include "TaskShopping.h"
#include "TaskEvent.h"
#include "TaskHomework.h"

template <typename T> class SortedLinkedList;
template <typename T> std::ostream& operator<<(std::ostream&, const SortedLinkedList<T>&);


template <typename T>
class SortedLinkedList {
 public:
  friend std::ostream& operator<< <T>(std::ostream& a, const SortedLinkedList<T>& rhs);

  unsigned int find_alphebet(node<T>* current , T* a);
  unsigned int find(T* a);
  void insert(node<T>* a, unsigned int position); 
  void remove(unsigned int position); 
  void push_in(T* a);
  unsigned int list_count();
  void print(bool detailed);
  node<T>* get_node(int i);
  void transfer(SortedLinkedList<T>& targetlist, int i); 
  void clear();

 private:
  Linklist<T> _list;
};



template <typename T> std::ostream& operator<<(std::ostream& a, const SortedLinkedList<T>& rhs) {
  a << rhs._list;
  return a;
}

template <typename T> unsigned int SortedLinkedList<T>::find_alphebet(node<T>* current , T* a ) {			//will only ever be called by find()
  node<T>* itr = current;
  unsigned int index = 0;
  //case for a's description[0] smaller than current's description[0]
  if ( (a->description()[0]%65)%32 < (itr->data->description()[0]%65)%32 ) {
    return 0;
  }

  for (;itr->data->dueDate().difference() == a->dueDate().difference(); itr = itr->p_next, ++index) {
    node<T>* itr_next = itr->p_next;

    //if end of list
    if(itr_next == NULL) {
      if ( (a->description()[0]%65)%32 <= (itr->data->description()[0]%65)%32 ) {  
        return index;
      }      
      if ( (a->description()[0]%65)%32 > (itr->data->description()[0]%65)%32 ) {    
        return ++index;
      }
    }
    
    //Will chk both front and back of any index of the list to find the right index to insert.
    if ( (a->description()[0]%65)%32 > (itr->data->description()[0]%65)%32 and (a->description()[0]%65)%32 < (itr_next->data->description()[0]%65)%32 ) { 
      return ++index;
    }
    //if element being chked are the same
    if ( (a->description()[0]%65)%32 == (itr->data->description()[0]%65)%32 ) { 	
      return index;
    }
  }

  //when dueDate.difference() is not same anymore.
  if (itr->data->dueDate().difference() != a->dueDate().difference()) {
    return index;
  }

  //default return, should never be called
  return 0;
}

template <typename T> unsigned int SortedLinkedList<T>::find(T* a) {
  unsigned int index = 0;
  node<T>* itr = _list.get_head();

  //if list is empty, then insert at first place
  if (_list.list_count() == 0) {  						
    return 0;
  }

  //first case of being earlier than the head's duedate
  if (a->dueDate().difference() < itr->data->dueDate().difference()) {    	
    return 0;
  }

  //Will chk both front and back of any index of the list to find the right index to insert.
  for (;itr != NULL; itr = itr->p_next, ++index) {
    node<T>* itr_next = itr->p_next;

    //in the case of chking that last element of the list
    if (itr_next == NULL) {
      if ( a->dueDate().difference() <= itr->data->dueDate().difference() ) {  	
        if (a->dueDate().difference() == itr->data->dueDate().difference()) {
          unsigned int tempindex = find_alphebet(itr, a);
          index += tempindex;
        }
        return index;
      }      
      if ( a->dueDate().difference() > itr->data->dueDate().difference() ) {    
        return ++index;
      }
    }

    //rest of the cases, where it chk both front and next of each element of the list
    if (a->dueDate().difference() > itr->data->dueDate().difference() and a->dueDate().difference() < itr_next->data->dueDate().difference()) { 
      return ++index;
    }
    //if element being chked are the same
    if (a->dueDate().difference() == itr->data->dueDate().difference()) { 	
      if (a->dueDate().difference() == itr->data->dueDate().difference()) {
          unsigned int tempindex = find_alphebet(itr, a);
          index += tempindex;
      }
      return index;
    }
  }
  //default return, shouldn't ever be called
  return index;
}

template <typename T> void SortedLinkedList<T>::remove(unsigned int position) {		//remove the node at a given index
  _list.remove(position);
}

template <typename T> void SortedLinkedList<T>::insert(node<T>* a, unsigned int position) {	//insert a node at a given index
  _list.insert(a,position);
}

template <typename T> void SortedLinkedList<T>::push_in(T* a) {
  unsigned int i = find(a);			//find the correct position to insert, then call insert fct
  node<T>* temp = _list.create_node(a);   
  _list.insert(temp,i);
}

template <typename T> unsigned int SortedLinkedList<T>::list_count() {
    return _list.list_count();
}

template <typename T> void SortedLinkedList<T>::print(bool detailed) {    	//false means print, true means detailed print
  _list.print(detailed);
}

template <typename T> node<T>* SortedLinkedList<T>::get_node(int i) {		//return a node from the list with a given index
  return _list.get_node(i);
}

template <typename T> void SortedLinkedList<T>::transfer(SortedLinkedList<T>& targetlist, int i) {	//transfer node from one list to another, not copying the node, it's merely playing with poiner
  node<T>* ptr = this->get_node(i);
  
  if (i == 1) {
    node<T>** ptrhead = this->_list.get_head_ptr();		
    *ptrhead = this->_list.get_head()->p_next;		//change the _head pointer to point to next in list.
    ptr->p_next = NULL;   			//reset its pointing to null, to disconnectd from inventory list
    unsigned int index = targetlist.find(ptr->data);			//imitate push_in(), but skip creating extra node to avoid memory leak
    targetlist._list.insert(ptr,index);

    this->_list.count_minus_one();
    return;
  }

  if (unsigned(i)== this->list_count()) {
    node<T>* ptrpre = _list.get_node(i-1);		//get the node right before it. this is safe, becasue at this point in the fct, we can confirm list_count is greater than 1.
    ptrpre->p_next = NULL;
    unsigned int index = targetlist.find(ptr->data);			//imitate push_in(), but skip creating extra node to avoid memory leak
    targetlist._list.insert(ptr,index);

    this->_list.count_minus_one();
    return; 
  }

  node<T>* ptrpre = this->_list.get_node(i-1);		//else rest of node is somewhere in middle of list
  ptrpre->p_next = ptr->p_next;
  ptr->p_next = NULL; 				//reset the node to point to NULL, to disconnect from original list
  unsigned int index = targetlist.find(ptr->data);			//imitate push_in(), but skip creating extra node to avoid memory leak
  targetlist._list.insert(ptr,index);

  this->_list.count_minus_one(); 
  return;
}

template <typename T> void SortedLinkedList<T>::clear() {		//clears list of dynamically allocated memory
  _list.clear();
}
#endif
