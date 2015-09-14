#ifndef ASTACK_HPP
#define ASTACK_HPP

#include <cassert>
#include "Stack.hpp"

const int DEFAULT_SIZE = 10;

template <class T>
class AStack : public Stack<T> {
private:
  int max_size;
  int top = 0;
  T* list; // the actual list of elements
public:
  AStack(int size=DEFAULT_SIZE);
  ~AStack();
  
  void push(const T&);
  T pop();
  const T& peek() const;
  void clear() { top = 0; }
  int size() { return top; }
};

template <class T>
AStack<T>::AStack(int size) {
  max_size = size;
  list = new T[size];
}

template <class T>
AStack<T>::~AStack() {
  delete [] list;
}  

template <class T>
void AStack<T>::push(const T& t) {
  //check if stack is full
  assert(top < max_size);
  list[top++] = t;
}

template <class T>
T AStack<T>::pop() {
  assert(top > 0);
  return list[--top];
}

template <class T>
const T& AStack<T>::peek() const {
  assert(top > 0);
  return list[top - 1];
}

#endif
