#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
  struct Node {
      T data;
      Node* next;
  };
  int num_of_elems;
  Node* head;
public:
  Stack(void) {
      this->head = new Node;
      this->num_of_elems = 0;
      this->head->next = NULL;
  }

  void push(const T& data) {
      if(this->num_of_elems == 0) {
          this->head->data = data;
          this->num_of_elems++;
          return;
      }
      Node* tmp = new Node;
      tmp->data = data;
      this->num_of_elems++;
      tmp->next = this->head;
      this->head = tmp;
  }

  T pick() {
      return this->head->data;
  }

  T pop() {
      Node* tmp = this->head;
      T res;
      if(!tmp) return res;
      this->num_of_elems--;
      res = tmp->data;
      this->head = tmp->next;
      delete tmp;
      return res;
  }

  Stack operator+(const Stack& stack) {
      Stack res;
      res = stack;
      T mas[this->num_of_elems];
      Node* tmp = this->head;
      for(int i = 0; i < this->num_of_elems; i++) {
          mas[i] = tmp->data;
          tmp = tmp->next;
      }
      for(int i = 0; i < this->num_of_elems; i++) {
          res.push(mas[this->num_of_elems - i - 1]);
      }
      return res;
  }

  void operator=(const Stack& stack) {
      Node* tmp = this->head;
      while(tmp) {
          Node *p = tmp->next;
          delete tmp;
          tmp = p;
      }
      this->head = new Node;
      this->num_of_elems = 0;
      this->head->next = NULL;

      T mas[stack.num_of_elems];
      tmp = stack.head;
      for(int i = 0; i < stack.num_of_elems; i++) {
          mas[i] = tmp->data;
          tmp = tmp->next;
      }
      for(int i = 0; i < stack.num_of_elems; i++) {
          this->push(mas[stack.num_of_elems - i - 1]);
      }
  }


  void print(void) {
      Node* tmp = this->head;
      while(tmp) {
          cout << tmp->data << " ";
          tmp = tmp->next;
      }
      cout << endl;
  }

  ~Stack(void) {
      Node* tmp = this->head;
      while(tmp) {
          Node* p = tmp->next;
          delete tmp;
          tmp = p;
      }
  }
};
