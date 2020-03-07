#include <iostream>
#include "ring.h"
using namespace std;

void Ring::addFirst(const char* lastname, const char* firstname, const char* patronimic, const int& age) {
    this->head->firstname = new char(20);
    this->head->lastname = new char(20);
    this->head->patronimic = new char(20);

    strcpy(this->head->firstname, firstname);
    strcpy(this->head->lastname, lastname);
    strcpy(this->head->patronimic, patronimic);
    this->head->age = age;
}

void Ring::addFront(const char* lastname, const char* firstname, const char* patronimic, const int& age) {
    if(this->head->firstname == NULL) return addFirst(lastname, firstname, patronimic, age);

    struct Node* tmp = new Node();
    tmp->firstname = new char(20);
    tmp->lastname = new char(20);
    tmp->patronimic = new char(20);

    strcpy(tmp->firstname, firstname);
    strcpy(tmp->lastname, lastname);
    strcpy(tmp->patronimic, patronimic);
    tmp->age = age;

    tmp->next = this->head->next;
    tmp->previous = this->head;
    this->head->next->previous = tmp;
    this->head->next = tmp;
}

void Ring::addBack(const char* lastname, const char* firstname, const char* patronimic, const int& age) {
    if(!this->head->firstname) return addFirst(lastname, firstname, patronimic, age);

    struct Node* tmp = new Node();
    tmp->firstname = new char(20);
    tmp->lastname = new char(20);
    tmp->patronimic = new char(20);

    strcpy(tmp->firstname, firstname);
    strcpy(tmp->lastname, lastname);
    strcpy(tmp->patronimic, patronimic);
    tmp->age = age;

    tmp->next = this->head;
    tmp->previous = this->head->previous;
    this->head->previous->next = tmp;
    this->head->previous = tmp;
}

void Ring::addAfter(const int& num, const char* lastname, const char* firstname, const char* patronimic, const int& age) {
    if(!this->head->firstname) return addFirst(lastname, firstname, patronimic, age);

    struct Node* cur = this->head;
    for(int i = 0; i < num; i++) cur = cur->next;

    struct Node* tmp = new Node();
    tmp->firstname = new char(20);
    tmp->lastname = new char(20);
    tmp->patronimic = new char(20);

    strcpy(tmp->firstname, firstname);
    strcpy(tmp->lastname, lastname);
    strcpy(tmp->patronimic, patronimic);
    tmp->age = age;

    tmp->next = cur->next;
    tmp->previous = cur;
    cur->next->previous = tmp;
    cur->next = tmp;
}

void Ring::addBefore(const int& num, const char* lastname, const char* firstname, const char* patronimic, const int& age) {
    this->addAfter(num - 1, lastname, firstname, patronimic, age);
}

void Ring::replace(void) {
    this->head = this->head->next;
}

void Ring::replace(const int& num) {
  for(int i = 0; i < num; i++) this->replace();
}

void Ring::remove() {
    if(this->head->next == this->head) {
        cout << "It is the last student in your list. Do you really want to remove him?\nIf yes, write 'y'\n";
        char c;
        cin >> c;
        if(c == 'y') {
            delete head->firstname;
            delete head->lastname;
            delete head->patronimic;
            delete head;
            this->head = new Node;
            this->head->firstname = NULL;
            this->head->lastname = NULL;
            this->head->patronimic = NULL;
            this->head->age = 0;
            this->head->previous = head->next = head;
        }
        return;
    }
    struct Node* tmp = this->head;
    this->head->previous->next = this->head->next;
    this->head->next->previous = this->head->previous;
    this->head = this->head->next;
    delete tmp->firstname;
    delete tmp->lastname;
    delete tmp->patronimic;
    delete tmp;
}

void Ring::removeAfter(const int& num) {
    if(this->head->next == this->head) {
        cout << "It is the last student in your list. Do you really want to remove him?\nIf yes, write 'y'\n";
        char c;
        cin >> c;
        if(c == 'y') {
            delete head->firstname;
            delete head->lastname;
            delete head->patronimic;
            delete head;
            this->head = new Node;
            this->head->firstname = NULL;
            this->head->lastname = NULL;
            this->head->patronimic = NULL;
            this->head->age = 0;
            this->head->previous = head->next = head;
        }
        return;
    }
    struct Node* tmp = this->head;
    for(int i = 0; i < num + 1; i++) tmp = tmp->next;
    if(tmp == this->head) this->head = this->head->next;
    struct Node* p = tmp;
    tmp->previous->next = tmp->next;
    tmp->next->previous = tmp->previous;
    tmp = tmp->next;
    delete p->firstname;
    delete p->lastname;
    delete p->patronimic;
    delete p;
}

void Ring::removeBefore(const int& num) {
    this->removeAfter(num - 2);
}

void Ring::print() {
    struct Node* tmp = this->head;
    do {
        printf("%s %s %s %d\n", tmp->lastname, tmp->firstname, tmp->patronimic, tmp->age);
        tmp = tmp->next;
    } while(tmp != this->head);
}

void printIntroduction(void) {
  printf("Hello\nThis program is used to create a curcle list\n");
  printf("This list is used to store information about students\n");
  printf("In every cell of list there are such parameters:\n");
  printf("1. Firstname\n");
  printf("2. Lastname\n");
  printf("3. Patronimic\n");
  printf("4. Age\n\n");
  printf("There are all comands you can use:\n");
  printf("1. Show all list\n");
  printf("2. Move pointer to the next student\n");
  printf("3. Add element to this position in list\n");
  printf("4. Add element before this position in list\n");
  printf("5. Add element after some elements in list\n");
  printf("6. Remove this element\n\n");
  printf("Lets start\n");
}

void printMenu(void) {
  printf("There are some comands you can write to interact with your list\n");
  printf("'A' or 'a' to ADD info about student AFTER current position\n");
  printf("'B' or 'b' to ADD info about student BEFORE curent position\n");
  printf("'P' or 'p' to ADD info about student after a certain number of students after current\n");
  printf("'O' or 'o' to ADD info about student before the student after a certain number of students after curent\n");
  printf("'R' or 'r' to REMOVE current student\n");
  printf("'W' or 'w' to REMOVE student AFTER a certain number of students after current\n");
  printf("'Z' of 'z' to REMOVE student BEFORE student after a certain number of students after current\n");
  printf("'M' or 'm' to MOVE pointer to the next student\n");
  printf("'N' or 'n' to MOVE pointer to a curtain number of students after current\n");
  printf("'S' or 's' to SHOW all list\n");
  printf("'I' or 'i' to show INFO about all comands again\n");
  printf("'Q' or 'q' to QUIT\n");
}
