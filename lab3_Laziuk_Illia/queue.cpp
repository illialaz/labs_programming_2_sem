#include <iostream>
#include "queue.h"
using namespace std;

Queue:: Queue(void) {
  this->num_of_elems = 0;
}

Queue:: Queue(const Queue& copy) {
  this->num_of_elems = copy.num_of_elems;
  for(int i = 0; i < this->num_of_elems; i++) this->mas[i] = copy.mas[i];
}

void Queue:: insert(void) {
  int tmp;
  cout << "Enter number of elements you want to add to your queue\n";
  cin>>tmp;
  cout << "You can add " << tmp << " elements to your queue. You need just to write them\n";
  int num;
  for(int i = 0; i < tmp; i++) {
    cin>>num;
    this->push(num);
  }
}

void Queue:: push(const int* mas, const int& num) {
  int res = num + this->num_of_elems <= 100 ? num : 100 - this->num_of_elems;
  for (int i = 0; i < res; i++) this->mas[this->num_of_elems++] = mas[i];
}

void Queue:: push(const int& num) {
  if(this->num_of_elems >= 100) return; // Queue is full
  this->mas[this->num_of_elems++] = num;
}

void Queue:: remove(void) {
  if(!this->num_of_elems) return; // Queue is empty
  this->num_of_elems--;
  for (int i = 0; i < this->num_of_elems; i++) this->mas[i] = this->mas[i+1];
}

void Queue:: remove(const int& num) {
  int res = num <= this->num_of_elems ? num : this->num_of_elems;
  this->num_of_elems -= res;
  for (int i = 0; i < this->num_of_elems; i++) this->mas[i] = this->mas[i + res];
}

int Queue:: getnum(void) {
  return this-> num_of_elems;
}

const int* Queue:: getmas(void) {
  return this->mas;
}

bool Queue:: compare(const Queue& queue) {
  if(this->num_of_elems != queue.num_of_elems) return false;
  for(int i = 0; i < this->num_of_elems; i++) if(this->mas[i] != queue.mas[i]) return false;
  return true;
}

void Queue:: print(void) {
  if(!this->num_of_elems) {
    cout << "Queue is empty\n";
    return;
  }
  for (int i = 0; i < this->num_of_elems; i++) cout << this->mas[i] << " ";
  cout << "\n" << this->num_of_elems << "\n";
}

bool Queue:: operator==(const Queue& queue) {
  if(this->num_of_elems != queue.num_of_elems) return false;
  for(int i = 0; i < this->num_of_elems; i++) if(this->mas[i] != queue.mas[i]) return false;
  return true;
}

bool Queue:: operator!=(const Queue& queue) {
  return !this->operator==(queue);
}

Queue Queue:: operator+(const Queue& queue) {
  Queue res(*this);
  res.push(queue.mas, queue.num_of_elems);
  return res;
}

void Queue:: operator=(const Queue& queue) {
  this->num_of_elems = queue.num_of_elems;
  for (int i = 0; i < queue.num_of_elems; i++) this->mas[i] = queue.mas[i];
}

void Queue:: operator+=(const Queue& queue) {
  this->push(queue.mas, queue.num_of_elems);
}

ostream& operator<<(ostream& out, const Queue& queue) {
  out << "Queue:\n";
  for(int i = 0; i < queue.num_of_elems; i++) out << queue.mas[i] << " ";
  out << "\n";
  return out;
}

istream& operator>>(istream& in, Queue& queue) {
  in >> queue.num_of_elems;
  for (int i = 0; i < queue.num_of_elems; i++) in >> queue.mas[i];
  return in;
}
