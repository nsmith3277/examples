#include <iostream>

int main() {

  int x = 10;
  int y = 20;
  std::cout << "x: " << x << "     y: " << y << std::endl;
  
  int* a = &x; // the address of x
  int* b = &y; // the address of y

  *b = 30; // the value of the object located at where b points
  std::cout << "x: " << x << "     y: " << y << std::endl;

  int** ap = &a;
  *ap = b;
  *a = 50; // what does this do?
  std::cout << "x: " << x << "     y: " << y << std::endl;


 
}
