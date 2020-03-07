#include <iostream>
#include "queue.h"
using namespace std;

int main(void) {
  Queue a;
  int abc;
  cout << "Abc\n";
  cin >> abc;
  for(int i = 1; i <= abc; i++) {
    a.push(i);
  }
  int mas[] = {1, 5, 8, 4, 345, 6, 7, 10};
  a.push(2);
  a.push(mas, 8);
  a.remove();
  a.remove(3);
  a.remove();
  a.insert();
  a.print();

  Queue b(a);
  if(a.compare(b)) cout << "Ok\n";
  if(a == b) cout << "Ok\n";
  b.remove(abc);
  b.print();

  Queue c;
  c = a + b;
  cout << c;

  Queue d;
  cin >> d;
  cout << d;

  Queue e(d);
  e += a;
  cout << e;
  if(e != d) cout << "Ok\n";
  return 0;
}
