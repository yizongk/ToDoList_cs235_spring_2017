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

template <typename T> unsigned int SortedLinkedList<T>::find(T* a) {
  if (_list.list_count() == 0) {		//acounts for empty list, will then behave differently in insert()
    return 0;
  }

  node<T>* itr = _list.get_head();

  for (unsigned int i = 0; itr != NULL; i++) {					//since list will be in smallest to largest number, hence latest to future
    if ( itr->data->dueDate().difference() == a->dueDate().difference() ) {		//ONLY BUG IS if NUMBER IS LEADING, that will mess up order
      node<T>* itr2 = itr;
      for (unsigned int j = i; itr2 !=NULL; j++) {
        if ( ( itr->data->dueDate().difference() == a->dueDate().difference() ) and ( ((itr2->data->description()[0]) % 65 ) % 32 >= ((a->description()[0]) % 65 )%32) ) { 
		std::cout<< "if ran" <<std::endl;
		std::cout<< int((itr2->data->description()[0]%65)%33) << " >= " << int((a->description()[0]%65)%33) << " --"<<i+j << std::endl;
          return (j + i);						//inner check for same difference of days, then chk for order of alphabet, other wise return i
        }

        if(itr2->p_next == NULL) {
          std::cout<< "NULL ran with: " << j+i+1 <<std::endl;
          return (j + i + 1);
        }
        itr2 = itr2->p_next;
      } 				
    }

    if ( itr->data->dueDate().difference() > a->dueDate().difference() ) {
      std::cout<< "2nd if: "<< std::endl;
      return i;
    }    

    itr = itr->p_next;
  }
  
  return _list.list_count();
}

template <typename T> void SortedLinkedList<T>::remove(unsigned int position) {
  _list.remove(position);
}

template <typename T> void SortedLinkedList<T>::insert(node<T>* a, unsigned int position) {
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

template <typename T> void SortedLinkedList<T>::print(bool detailed) {
  _list.print(detailed);
}

template <typename T> node<T>* SortedLinkedList<T>::get_node(int i) {
  return _list.get_node(i);
}

template <typename T> void SortedLinkedList<T>::transfer(SortedLinkedList<T>& targetlist, int i) {
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

template <typename T> void SortedLinkedList<T>::clear() {
  _list.clear();
}
#endif
