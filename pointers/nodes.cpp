#include <iostream>

struct node {
  node* next = 0;
  int data;
  node(const int& t) { data = t; }
  ~node() { delete next; }
};

struct LL {
  node* start = 0;
  
  LL() {}
  ~LL();
  
  void insert(const int& t);
  void insert(const int& t, node* n);
  void remove(const int& t);
  void remove(const int& t, node* n);
};

void LL::insert(const int& t) {
  if (start)
    insert(t, start);
  else
    start = new node(t);
}

void LL::insert(const int& t, node* n) {
  if (node->next)
    insert(t, node->next);
  else
    node->next = new node(t);
}

void LL::remove(const int& t) {
  if (start)
    remove(t, start, &start);
}

void LL::remove(const int& t, node* n, node** to_me) {
  if (n->data == t) {
    *to_me = n->next;
  }
  else {
    remove(t, n->next, &n->next);
  }
}
