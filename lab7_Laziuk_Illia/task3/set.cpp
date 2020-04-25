#include <iostream>
#include <string>
#include "set.h"
using namespace std;

Set_int::Set_int() {
  this->all_elems= 0;
  this->data = NULL;
}

Set_int::Set_int(const Set_int& set) {
    this->data = new int[set.all_elems];
    this->all_elems = set.all_elems;
    for(int i = 0; i < this->all_elems; i++) {
      this->data[i] = set.data[i];
    }
}

void Set_int::add(const int& elem) {
  for(int i = 0; i < this->all_elems; i++) {
        if(elem == this->data[i]) return;
    }
    int* res = new int[(this->all_elems + 1)];
    for(int i = 0; i < this->all_elems; i++) {
        res[i] = this->data[i];
    }
    res[this->all_elems++] = elem;
    if(this->data != NULL) delete[] this->data;
    this->data = new int[this->all_elems];
    for(int i = 0; i < this->all_elems; i++) {
        this->data[i] = res[i];
    }
    delete[] res;
}

void Set_int::remove(const int& elem) {
    if(this->all_elems == 0) return;
    int tmp = -1;
    for(int i = 0; i < this->all_elems; i++) {
        if(elem == this->data[i]) { tmp = i; break; }
    }
    if(tmp != -1) {
        int* res = new int[this->all_elems - 1];
        for(int i = 0; i < this->all_elems; i++) {
            if(i < tmp) res[i] = this->data[i];
            if(i > tmp) res[i - 1] = this->data[i];
        }
        delete[] this->data;
        if(--this->all_elems == 0) {
            this->data = NULL; // ?
            delete[] res;
            return;
        }
        this->data = new int[this->all_elems];
        for(int i = 0; i < this->all_elems; i++) {
            this->data[i] = res[i];
        }
        delete[] res;
    }
}

void Set_int::operator=(const Set_int& tmp) {
  delete[] data;
    if(tmp.all_elems == 0) {
        this->data = NULL;
        this->all_elems = 0;
        return;
    }
    this->all_elems = tmp.all_elems;
    this->data = new int[this->all_elems];
    for(int i = 0; i < this->all_elems; i++) this->data[i] = tmp.data[i];
}

void Set_int::sum(const Set& a) {
  Set_int& tmp = *((Set_int*)&a);
  if(this->all_elems == 0 && tmp.all_elems == 0) {
    return;
    }
    else if (this->all_elems > tmp.all_elems) {
        for(int i = 0; i < tmp.all_elems; i++) this->add(tmp.data[i]);
    }
    else {
        Set_int res(tmp);
        for(int i = 0; i < this->all_elems; i++) res.add(this->data[i]);
        *this = res;
    }
}

void Set_int::mult(const Set& a) {
  Set_int& tmp = *((Set_int*)&a);
  Set_int res;
    for(int i = 0; i < this->all_elems; i++) {
        for(int j = 0; j < tmp.all_elems; j++) {
            if(this->data[i] == tmp.data[j]) res.add(this->data[i]);
        }
    }
    *this = res;
}

void Set_int::sim_sub(const Set& a) {
  Set_int& tmp = *((Set_int*)&a);
  Set_int res;
    for(int i = 0; i < this->all_elems; i++) res.add(this->data[i]);

    Set_int p;
    for(int i = 0; i < tmp.all_elems; i++) p.add(tmp.data[i]);

    for(int i = 0; i < res.all_elems; i++) {
        for(int j = 0; j < p.all_elems; j++) {
            if(p.all_elems > 0 && res.all_elems > 0) {
                if (p.data[j] == res.data[i]) {
                    res.remove(res.data[i]);
                    p.remove(p.data[j]);
                    i--;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < tmp.all_elems; i++) res.add(p.data[i]);
    *this = res;
}

void Set_int::sort() {
  for(int i = 0; i < this->all_elems; i++) {
        for(int j = i; j < this->all_elems; j++) {
            if(this->data[i] > this->data[j]) {
                int tmp = this->data[i];
                this->data[i] = this->data[j];
                this->data[j] = tmp;
                i--;
                j--;
            }
        }
    }
}

void Set_int::print() {
    this->sort();
    for(int i = 0; i < this->all_elems; i++) {
        cout << this->data[i] << endl;
    }
    cout << endl;
}

Set_int::~Set_int() {
  delete[] this->data;
}

Set_string::Set_string() {
  this->all_elems = 0;
  this->data = NULL;
}

Set_string::Set_string(const Set_string& set) {
    this->data = new string[set.all_elems];
    this->all_elems = set.all_elems;
    for(int i = 0; i < this->all_elems; i++) {
        this->data[i] = set.data[i];
    }
}

void Set_string::add(const string& elem) {
  for(int i = 0; i < this->all_elems; i++) {
        if(elem == this->data[i]) return;
    }
    string* res = new string[(this->all_elems + 1)];
    for(int i = 0; i < this->all_elems; i++) {
        res[i] = this->data[i];
    }
    res[this->all_elems++] = elem;
    if(this->data != NULL) delete[] this->data;
    this->data = new string[this->all_elems];
    for(int i = 0; i < this->all_elems; i++) {
        this->data[i] = res[i];
    }
    delete[] res;
}

void Set_string::remove(const string& elem) {
    if(this->all_elems == 0) return;
    int tmp = -1;
    for(int i = 0; i < this->all_elems; i++) {
        if(elem == this->data[i]) { tmp = i; break; }
    }
    if(tmp != -1) {
        string* res = new string[this->all_elems - 1];
        for(int i = 0; i < this->all_elems; i++) {
            if(i < tmp) res[i] = this->data[i];
            if(i > tmp) res[i - 1] = this->data[i];
        }
        delete[] this->data;
        if(--this->all_elems == 0) {
            this->data = NULL;
            delete[] res;
            return;
        }
        this->data = new string[this->all_elems];
        for(int i = 0; i < this->all_elems; i++) {
            this->data[i] = res[i];
        }
        delete[] res;
    }
}

void Set_string::operator=(const Set_string& tmp) {
  delete[] data;
    if(tmp.all_elems == 0) {
        this->data = NULL;
        this->all_elems = 0;
        return;
    }
    this->all_elems = tmp.all_elems;
    this->data = new string[this->all_elems];
    for(int i = 0; i < this->all_elems; i++) this->data[i] = tmp.data[i];
}

void Set_string::sum(const Set& a) {
  Set_string& tmp = *((Set_string*)&a);
  if(this->all_elems == 0 && tmp.all_elems == 0) {
    return;
    }
    else if (this->all_elems > tmp.all_elems) {
        for(int i = 0; i < tmp.all_elems; i++) this->add(tmp.data[i]);
    }
    else {
        Set_string res(tmp);
        for(int i = 0; i < this->all_elems; i++) res.add(this->data[i]);
        *this = res;
    }
}

void Set_string::mult(const Set& a) {
  Set_string& tmp = *((Set_string*)&a);
  Set_string res;
    for(int i = 0; i < this->all_elems; i++) {
        for(int j = 0; j < tmp.all_elems; j++) {
            if(this->data[i] == tmp.data[j]) res.add(this->data[i]);
        }
    }
    *this = res;
}

void Set_string::sim_sub(const Set& a) {
  Set_string& tmp = *((Set_string*)&a);
  Set_string res;
    for(int i = 0; i < this->all_elems; i++) res.add(this->data[i]);

    Set_string p;
    for(int i = 0; i < tmp.all_elems; i++) p.add(tmp.data[i]);

    for(int i = 0; i < res.all_elems; i++) {
        for(int j = 0; j < p.all_elems; j++) {
            if(p.all_elems > 0 && res.all_elems > 0) {
                if (p.data[j] == res.data[i]) {
                    res.remove(res.data[i]);
                    p.remove(p.data[j]);
                    i--;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < p.all_elems; i++) res.add(p.data[i]);
    *this = res;
}

void Set_string::sort() {
  for(int i = 0; i < this->all_elems; i++) {
        for(int j = i; j < this->all_elems; j++) {
            if(this->data[i] > this->data[j]) {
                string tmp = this->data[i];
                this->data[i] = this->data[j];
                this->data[j] = tmp;
            }
        }
    }
}

void Set_string::print() {
  this->sort();
  for(int i = 0; i < this->all_elems; i++) {
        cout << this->data[i] << endl;
    }
    cout << endl;
}

Set_string::~Set_string() {
  delete[] this->data;
}