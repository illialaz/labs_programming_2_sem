#include <iostream>
#include "matrix.h"
using namespace std;

int main(void) {
  bool e = true;
  while(e) {
    int n;
    Imatrix* p;
    Imatrix* q;
    Imatrix* pq;
    cout << "int/double?\n";
    cin >> n;
    if(n == 1) {
      matrix_int a, b, c;
      p = &a; q = &b; pq = &c;
    }
    else {
      matrix_double a, b, c;
      p = &a; q = &b; pq = &c;
    }
    bool d = true;
    while(d) {
      cout << "1.Put(a)\n2.Print(a)\n3.Put(b)\n4.Print(b)\n5.Print(a+b)\n6.Exit\n";
      cin >> n;
      switch(n) {
        case 1:
          p->put();
          break;
        case 2:
          p->print();
          break;
        case 3:
          q->put();
          break;
        case 4:
          q->print();
          break;
        // case 5:
        //   pq->add(p);
        //   pq->add(q);
        //   pq->print();
        //   pq->remove();
        //   break;
        case 6:
          d = false;
          break;
      }
    }
    cout << "1.Again\n2.Exit\n";
    cin >> n;
    switch(n) {
      case 1:
        break;
      case 2:
        e = false;
        break;
    }
  }
  return 0;
}