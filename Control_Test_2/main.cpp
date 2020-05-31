#include <iostream>
#include <string>
#include <fstream>
#include "dequeue.h"

int main(void) {
  DequeueInt a;
  ifstream InInt("input1.txt");
  if(!InInt) return -1;
  InInt >> a;
  DequeueInt b(a);
  b.pushBack(1);
  b.pushFront(3);
  a.add(b);
  cout << a.popBack() << endl;
  cout << a.popFront() << endl;
  a.binOut("output.bin");
  b.copy(a);
  cout << b << endl;
  b.removeAll();
  b.pushBack(1);
  cout << b << endl;

  DequeueString c;
  ifstream InString("input2.txt");
  if(!InString) return -2;
  InString >> c;
  DequeueString d(c);
  d.pushBack("asdf");
  d.pushFront("qwer");
  c.add(d);
  cout << c.popBack() << endl;
  cout << c.popFront() << endl;
  ofstream Out("output.txt");
  Out << c << endl;
  cout << d << endl;
  return 0;
}
