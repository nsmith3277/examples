#ifndef LQUEUE_HPP
#define LQUEUE_HPP

/*
  A linked list implementation of the Queue ADT
 */

#include <cassert>
#include "Queue.hpp"

template <class T>
struct LQueue_Node {
  T data;
  LQueue_Node<T>* next;
  LQueue_Node(const T& t) { data = t; }
};

template <class T>
class LQueue : public Queue<T> {
private:
  LQueue_Node<T>* front = 0, *back = 0;
  int count = 0;
public:
  LQueue() {}
  ~LQueue();

  void enqueue(const T&);
  T dequeue();
  const T& peek() const; 
  void clear() { while(count > 0) dequeue(); }
  int size() { return count; }
};

template <class T>
LQueue<T>::~LQueue() {
  clear();
}

template <class T>
void LQueue<T>::enqueue(const T& t) {
  if (front) {
    back->next = new LQueue_Node<T>(t);
    back = back->next;
  } else {
    back = front = new LQueue_Node<T>(t);
  }
  ++count;
}

template <class T>
T LQueue<T>::dequeue() {
  assert(count > 0);
  LQueue_Node<T>* temp = front;
  front = front->next;
  T ret = temp->data;
  delete temp;
  --count;
  return ret;
}

template <class T>
const T& LQueue<T>::peek() const {
  assert(count > 0);
  return front->data;
}

#endif
