#include <iostream>
#include <string>
#include "list.h"
using namespace std;

int main(void) {
  int tmp = 1;
  List<Student> students;
  Student data;

  printmenu();
  
  while(tmp) {
    int a;
    cin >> a;
    switch(a) {
      case 1:
        cin >> data;
        students.add(data);
        break;
      case 2:
        cout << students.get();
        break;
      case 3:
        students.moveForward();
        break;
      case 4:
        students.moveBack();
        break;
      case 5:
        cout << students.pick();
        break;
      case 6:
        students.print();
        break;
      case 7:
        printmenu();
        break;
      case 0:
        tmp = 0;
        break;
    }
  }
  return 0;
}
