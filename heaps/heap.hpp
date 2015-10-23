// making a heap

#ifndef HEAP_HPP
#define HEAP_HPP

#include <cassert>
#include <iostream>
#include <vector>

class Heap {
private:
  // holds the tree
  std::vector<int> tree;
  
  // index of the last element added
  int position = 0;
public:
  Heap() { tree.resize(2); }
  ~Heap() {}
  
  // add an element to the tree
  void enqueue(const int&);
  // fix the heap from a specific index up
  void fix_up(const int&);

  // remove the smallest element
  int dequeue();
  // fix the tree after replacing the smallest element
  void fix_down(const int&);

  void swap(const int&, const int&);
  void display();
   
};

void Heap::enqueue(const int& t) {
  // check to see if we need to expand the vector
  if (position == tree.size() - 1)
    tree.resize(tree.size() * 2);

  // insert at the next position
  tree[++position] = t;

  // fix up to the root (or until we dont need to swap)
  fix_up(position);
  // done
}

void Heap::fix_up(const int& t) {
  // at the top of the tree
  if (t == 1)
    return;

  // if current is < its parent
  if (tree[t] < tree[t/2]) {
    swap(t, t/2);
    fix_up(t/2);
  }
}

int Heap::dequeue() {
  assert(position);

  int ret = tree[1];
  swap(1, position--);
  fix_down(1);
  return ret;
}
 
void Heap::fix_down(const int& t) {
  

}

void Heap::swap(const int& a, const int& b) {
  int temp = tree[a];
  tree[a] = tree[b];
  tree[b] = temp;
}

void Heap::display() {
  for (int i = 1; i <= position; ++i)
    std::cout << "[" << tree[i] << "]";
  std::cout << std::endl;
}

#endif
 
