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
  cout << "You can add some elements to your queue. You need just to write them\n";
  cout << "If you want to exit then write some letter(for example \"n\" and then click Enter\n";
  int num;
  while(cin>>num) this->push(num);
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

bool Queue:: compare(const Queue& tmp) {
  if(this->num_of_elems != tmp.num_of_elems) return false;
  for(int i = 0; i < this->num_of_elems; i++) if(this->mas[i] != tmp.mas[i]) return false;
  return true;
}

void Queue:: print(void) {
  if(!this->num_of_elems) {
    cout << "Queue is empty\n";
    return;
  }
  for (int i = 0; i < this->num_of_elems; i++) cout << this->mas[i] << " ";
  cout << "\n\n" << this->num_of_elems << "\n";
}
