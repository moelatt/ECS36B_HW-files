//
// useVelocity.cpp
//

#include "Velocity.h"
#include <iostream>
using namespace std;

int main()
{
  Velocity v;
  v.print();
  v.accelerate(25); v.print();
  v.accelerate(65); v.print();
  v.accelerate(-72); v.print();
  v.accelerate(65); v.print();
  v.accelerate(-35); v.print();
  v.accelerate(0); v.print();
  v.accelerate(-4); v.print();
  v.accelerate(-5); v.print();
  v.accelerate(-10); v.print();
  v.accelerate(3); v.print();

  v.accelerate(10);
  cout << v.get() << endl;
}