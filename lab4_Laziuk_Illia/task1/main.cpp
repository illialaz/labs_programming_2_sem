#include <iostream>
#include <ctype.h>
#include "ring.h"

using namespace std;

int main(void) {
  printIntroduction();
  printMenu();
  bool quit = false;
  char a;
  char* firstname = new char(20);
  char* lastname = new char(20);
  char* patronimic = new char(20);
  char* age = new char(2);
  char* num = new char(3);
  Ring Student;
  while(!quit) {
    cin >> a;
    if(isupper(a)) a = tolower(a);
    switch (a) {
      case 'a': 
        cout << "Enter lastname of student, then name, then patronimic, and age\n";
        cin >> lastname >> firstname >> patronimic >> age;
        Student.addFront(lastname, firstname, patronimic, atoi(age));
        cout << "\nOK\n";
        break;

      case 'b':
        cout << "Enter lastname of student, then name, then patronimic, and age\n";
        cin >> lastname >> firstname >> patronimic >> age;
        Student.addBack(lastname, firstname, patronimic, atoi(age));
        cout << "\nOK\n";
        break;

      case 'p':
        cout << "Enter number, then lastname of student, then name, then patronimic, and age\n";
        cin >> num >> lastname >> firstname >> patronimic >> age;
        Student.addAfter(atoi(num), lastname, firstname, patronimic, atoi(age));
        cout << "\nOK\n";
        break;

      case 'o':
        cout << "Enter number, then lastname of student, then name, then patronimic, and age\n";
        cin >> num >> lastname >> firstname >> patronimic >> age;
        Student.addBefore(atoi(num), lastname, firstname, patronimic, atoi(age));
        cout << "\nOK\n";
        break;

      case 'r':
        Student.remove();
        cout << "\nOK\n";
        break;

      case 'w':
        cout << "Enter number of student you want to remove\n";
        cin >> num;
        Student.removeAfter(atoi(num));
        cout << "\nOK\n";
        break;

      case 'z':
        cout << "Enter number of student you want to remove\n";
        cin >> num;
        Student.removeBefore(atoi(num));
        cout << "\nOK\n";
        break;

      case 'm':
        Student.replace();
        cout << "\nOK\n";
        break;

      case 'n':
        cout << "Enter number you want to move after current student\n";
        cin >> num;
        Student.replace(atoi(num));
        cout << "\nOK\n";
        break;

      case 's':
        Student.print();
        cout << "\nOK\n";
        break;

      case 'i':
        printMenu();
        cout << "\nOK\n";
        break;

      case 'q':
        quit = true;
        break;

      default:
        cout << "\nError, try again\n";
        break;
    }
  }
  return 0;
}
