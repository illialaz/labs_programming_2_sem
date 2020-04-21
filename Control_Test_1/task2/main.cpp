#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main(void) {
  Stack<int> a;
  for(int i = 1; i < 4; i++) {
      a.push(i);
  }
  Stack<int> b;
  b = a;
  b.push(13);
  b.push(14);
  Stack<int> c;
  c = a + b;
  c.print();
  cout << c.pop() << endl;
  c.print();
  cout << c.pick() << endl;
  c.print();
  for(int i = 0; i < 3; i++) cout << a.pop() << endl;
  a.print();
  
  
  Stack<string> d;
  string q = "asd";
  string w = "qw";
  string y = "ert";
  string r = "dfg";
  string t = "cvb";
  d.push(q);
  d.push(w);
  d.push(y);
  Stack<string> e;
  e = d;
  e.push(r);
  e.push(t);
  Stack<string> f;
  f = d + e;
  f.print();
  cout << f.pop() << endl;
  f.print();
  cout << f.pick() << endl;
  f.print();
  for(int i = 0; i < 4; i++) cout << d.pop() << endl;
  d.print();
}