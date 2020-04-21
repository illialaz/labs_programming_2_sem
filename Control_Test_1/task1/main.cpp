#include <iostream>
#include "weight.h"
using namespace std;

int main(void) {
  Weight a, b, c;
  cin >> a >> b;
  cout << a + b;
  cout << a - b;
  cout << a * 2.35;
  cout << a / 3.14;
  c = a + b;
  cout << c;
  return 0;
}