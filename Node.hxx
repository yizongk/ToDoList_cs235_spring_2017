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

template <typename T> void node<T>::print(bool detailed) {
  if(detailed == true) {
    std::cout<<*data; 
  } else {
    data->print();
  }
}


#endif


