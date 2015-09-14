#ifndef STACK_HPP
#define STACK_HPP

template <class T>
class Stack
{
private:
  
public:
  Stack() {}
  virtual ~Stack() {}

  virtual void push(const T&)=0;
  virtual T pop()=0;
  virtual const T& peek() const =0;
  virtual void clear()=0;
  virtual int size()=0;
};

#endif
