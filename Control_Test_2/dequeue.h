#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<typename T>
struct Node {
  Node* next;
  Node* prev;
  T data;
  Node(const T& val): next(NULL), prev(NULL), data(val){}
};

class Dequeue {
public:
  virtual void add(const Dequeue&) = 0;
  virtual void copy(const Dequeue&) = 0;
};

class DequeueInt : public Dequeue {
private:
  Node<int>* start;
  Node<int>* finish;
public:
  DequeueInt() {
    start = finish = NULL;
  }
  DequeueInt(const DequeueInt& tmp) {
    Node<int>* p = tmp.start;
    while(p) {
      this->pushBack(p->data);
      p = p->next;
    }
  }
  void pushBack(const int& val) {
    Node<int>* p = new Node<int>(val);
      if(start == NULL)
          start = finish = p;
      else {
          p->prev  = finish;
          finish->next = p;
          finish = p;
      }
  }
  void pushFront(const int& val) {
    Node<int>* p = new Node<int>(val);
        if(start == NULL)
            start = finish = p;
        else {
            p->next = start;
            start->prev = p;
            start = p;
        }
  }
  int popBack() {
    Node<int>* del;
    int res;
    if(finish != NULL){
      del = finish;
      finish = finish->prev;
      res = del->data;
      delete del;
      if(finish == NULL) start = NULL;
      else finish->next = NULL;
      return res;
    }
  }
  int popFront() {
    Node<int>* del;
    int res;
    if(start != NULL){
        del = start;
        start = start->next;
        res = del->data;
        delete del;
        if(start == NULL) finish = NULL;
        else start->prev = NULL;
    }
    return res;
  }
  void add(const Dequeue& tmp) override {
    DequeueInt& tmp1 = *((DequeueInt*)&tmp);
    Node<int>* p = tmp1.start;
    while(p) {
      this->pushBack(p->data);
      p = p->next;
    }
  }
  void copy(const Dequeue& tmp) override {
    this->removeAll();
    DequeueInt& tmp1 = *((DequeueInt*)&tmp);
    Node<int>* p = tmp1.start;
    while(p) {
      this->pushBack(p->data);
      p = p->next;
    }
  }
  void removeAll(){
    Node<int>* tmp;
    while(start != NULL){
        tmp = start;
        start = start->next;
        delete tmp;
    }
    finish = NULL;
  }
  friend istream& operator>>(istream& in, DequeueInt& tmp) {
    tmp.removeAll();
    int a;
    in >> a;
    for(int i = 0; i < a; i++) {
      in >> a;
      tmp.pushBack(a);
    }
    return in;
  }
  friend ostream& operator<<(ostream& out, const DequeueInt& tmp) {
    Node<int>* tmp1 = tmp.start;
    while(tmp1) {
      out << tmp1->data << " ";
      tmp1 = tmp1->next;
    }
    return out;
  }
  void binOut(string name) {
    ofstream Out(name, ios::out | ios::binary);
    Node<int>* tmp1 = this->start;
    while(tmp1) {
      Out.write((char*)&tmp1->data, sizeof(int));
      tmp1 = tmp1->next;
    }
  }
  ~DequeueInt() {
    Node<int>* tmp;
    while(start != NULL){
        tmp = start;
        start = start->next;
        delete tmp;
    }
  }
};

class DequeueString : public Dequeue {
private:
  Node<string>* start;
  Node<string>* finish;
public:
  DequeueString() {
    start = finish = NULL;
  }
  DequeueString(const DequeueString& tmp) {
    Node<string>* p = tmp.start;
    while(p) {
      this->pushBack(p->data);
      p = p->next;
    }
  }
  void pushBack(const string& val) {
    Node<string>* p = new Node<string>(val);
      if(start == NULL)
          start = finish = p;
      else {
          p->prev = finish;
          finish->next = p;
          finish = p;
      }
  }
  void pushFront(const string& val) {
    Node<string>* p = new Node<string>(val);
        if(start == NULL)
            start = finish = p;
        else {
            p->next = start;
            start->prev = p;
            start = p;
        }
  }
  string popBack() {
    Node<string>* del;
    string res;
    if(finish != NULL){
      del = finish;
      finish = finish->prev;
      res = del->data;
      delete del;
      if(finish == NULL) start = NULL;
      else finish->next = NULL;
      return res;
    }
  }
  string popFront() {
    Node<string>* del;
    string res;
    if(start != NULL){
        del = start;
        start = start->next;
        res = del->data;
        delete del;
        if(start == NULL) finish = NULL;
        else start->prev = NULL;
    }
    return res;
  }
  void add(const Dequeue& tmp) override {
    DequeueString& tmp1 = *((DequeueString*)&tmp);
    Node<string>* p = tmp1.start;
    while(p) {
      this->pushBack(p->data);
      p = p->next;
    }
  }
  void copy(const Dequeue& tmp) override {
    this->removeAll();
    DequeueString& tmp1 = *((DequeueString*)&tmp);
    Node<string>* p = tmp1.start;
    while(p) {
      this->pushBack(p->data);
      p = p->next;
    }
  }
  void removeAll(){
    Node<string>* tmp;
    while(start != NULL){
        tmp = start;
        start = start->next;
        delete tmp;
    }
    finish = NULL;
  }
  friend istream& operator>>(istream& in, DequeueString& tmp) {
    tmp.removeAll();
    int a;
    in >> a;
    for(int i = 0; i < a; i++) {
      string b;
      in >> b;
      tmp.pushBack(b);
    }
    return in;
  }
  friend ostream& operator<<(ostream& out, const DequeueString& tmp) {
    Node<string>* tmp1 = tmp.start;
    while(tmp1) {
      out << tmp1->data << " ";
      tmp1 = tmp1->next;
    }
    return out;
  }
  ~DequeueString() {
    Node<string>* tmp;
    while(start != NULL){
        tmp = start;
        start = start->next;
        delete tmp;
    }
  }
};
