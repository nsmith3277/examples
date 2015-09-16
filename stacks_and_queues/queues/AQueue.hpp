#ifndef AQUEUE_HPP
#define AQUEUE_HPP

/*
  An array based implementation of the Queue ADT
 */

#include <cassert>
#include "Queue.hpp"

const int DEFAULT_QUEUE_SIZE = 10; 

template <class T>
class AQueue : public Queue<T> {
private:
  int max_size = 0;
  int count = 0;
  int front = 0;
  T* list;
public:
  AQueue(const int size=DEFAULT_QUEUE_SIZE);
  ~AQueue();

  void enqueue(const T&);
  T dequeue();
  const T& peek() const; 
  void clear() { front = count = 0; }
  int size() { return count; }
};

template <class T>
AQueue<T>::AQueue(const int size) {
  max_size = size;
  list = new T[size];
}

template <class T>
AQueue<T>::~AQueue() {
  delete [] list;
}

template <class T>
void AQueue<T>::enqueue(const T& t) {
  // make sure we arent full
  assert(count < max_size);

  // set the element at the correct position (with wrapping) and update count
  list[(front + count++) % max_size] = t;
}

template <class T>
T AQueue<T>::dequeue() {
  // make sure we arent empty
  assert(count > 0);
  
  // store the element at the front
  T ret = list[front];

  // adjust front
  front = (--count == 0 ? 0 : ++front % max_size);
  
  return ret;
}

template <class T>
const T& AQueue<T>::peek() const {
  assert(count > 0);
  
  return list[front];
}

#endif
