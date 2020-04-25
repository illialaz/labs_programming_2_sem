#include <iostream>
#include <stdarg.h>
using namespace std;

template <typename T>
class Set {
  private:
    int all_elems;
    T* data;
  public:
    Set(){ data = NULL; all_elems = 0; }
    Set(int, T, ...);
    Set(int, T*);
    Set(const Set&);
    void add(const T&);
    void remove(const T&);
    T& operator[] (const int);
    void operator=(const Set&);
    Set operator+(const Set&);
    Set operator*(const Set&);
    Set operator-(const Set&);
    void print();
    void sort();
    ~Set();
};

template<typename T>
Set<T>::Set(int num, T first, ...) {
    this->all_elems = 0;
    T* res = new T[num];
    va_list elems;
    va_start(elems, first);
    bool a = true;
    res[this->all_elems++] = first;
    for(int i = 0; i < num - 1; i++) {
        a = true;
        T tmp = va_arg(elems, T);
        for(int j = 0; j < this->all_elems; j++) {
            if(tmp == res[j]) {
                a = false;
                break;
            }
        }
        if(a) {
            res[this->all_elems++] = tmp;
        }
    }
    va_end(elems);
    this->data = new T[this->all_elems];
    for(int i = 0; i < this->all_elems; i++) {
        this->data[i] = res[i];
    }
    delete[] res;
}

template<typename T>
Set<T>::Set(int size, T* mas) {
    this->all_elems = 0;
    T* res = new T[size];
    for(int i = 0; i < size; i++) {
        bool a = true;
        for(int j = 0; j < this->all_elems; j++) {
            if(mas[i] == res[j]) {
                a = false;
                break;
            }
        }
        if(a) res[this->all_elems++] = mas[i];
    }
    this->data = new T[this->all_elems];
    for(int i = 0; i < this->all_elems; i++) {
        this->data[i] = res[i];
    }
    delete[] res;
}

template <typename T>
Set<T>::Set(const Set& set) {
    this->data = new T[set.all_elems];
    this->all_elems = set.all_elems;
    for(int i = 0; i < this->all_elems; i++) {
        this->data[i] = set.data[i];
    }
}

template <typename T>
void Set<T>::add(const T& elem) {
    for(int i = 0; i < this->all_elems; i++) {
        if(elem == this->data[i]) return;
    }
    T* res = new T[(this->all_elems + 1)];
    for(int i = 0; i < this->all_elems; i++) {
        res[i] = this->data[i];
    }
    res[this->all_elems++] = elem;
    if(this->data != NULL) delete[] this->data;
    this->data = new T[this->all_elems];
    for(int i = 0; i < this->all_elems; i++) {
        this->data[i] = res[i];
    }
    delete[] res;
}

template <typename T>
void Set<T>::remove(const T& elem) {
    if(this->all_elems == 0) return;
    int tmp = -1;
    for(int i = 0; i < this->all_elems; i++) {
        if(elem == this->data[i]) { tmp = i; break; }
    }
    if(tmp != -1) {
        T* res = new T[this->all_elems - 1];
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
        this->data = new T[this->all_elems];
        for(int i = 0; i < this->all_elems; i++) {
            this->data[i] = res[i];
        }
        delete[] res;
    }
}

template <typename T>
T& Set<T>::operator[](const int num) {
    if(num < 1 || num > this->all_elems) {
        cout << "Error";
        return this->data[0];
    }
    return this->data[num - 1];
}

template <typename T>
void Set<T>::operator=(const Set& tmp) {
    delete[] data;
    if(tmp.all_elems == 0) {
        this->data = NULL;
        this->all_elems = 0;
        return;
    }
    this->all_elems = tmp.all_elems;
    this->data = new T[this->all_elems];
    for(int i = 0; i < this->all_elems; i++) this->data[i] = tmp.data[i];
}

template <typename T>
Set<T> Set<T>::operator+(const Set& tmp) {
    if(this->all_elems == 0 && tmp.all_elems == 0) {
        Set<T> res;
        return res;
    }
    else if (this->all_elems > tmp.all_elems) {
        Set<T> res(*this);
        for(int i = 0; i < tmp.all_elems; i++) res.add(tmp.data[i]);
        return res;
    }
    else {
        Set<T> res(tmp);
        for(int i = 0; i < this->all_elems; i++) res.add(this->data[i]);
        return res;
    }
}

template <typename T>
Set<T> Set<T>::operator*(const Set& tmp) {
    Set<T> res;
    for(int i = 0; i < this->all_elems; i++) {
        for(int j = 0; j < tmp.all_elems; j++) {
            if(this->data[i] == tmp.data[j]) res.add(this->data[i]);
        }
    }
    return res;
}

template <typename T>
Set<T> Set<T>::operator-(const Set& tmp) {
    Set<T> res;
    for(int i = 0; i < this->all_elems; i++) res.add(this->data[i]);

    Set<T> p;
    for(int i = 0; i < tmp.all_elems; i++) p.add(tmp.data[i]);

    for(int i = 0; i < res.all_elems; i++) {
        for(int j = 0; j < tmp.all_elems; j++) {
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
    return res;
}

template<typename T>
void Set<T>::print(){
    for(int i = 0; i < this->all_elems; i++) {
        cout << this->data[i] << endl;
    }
    cout << endl;
}

template<typename T>
void Set<T>::sort() {
    for(int i = 0; i < this->all_elems; i++) {
        for(int j = i; j < this->all_elems; j++) {
            if(this->data[i] < this->data[j]) {
                T tmp = this->data[i];
                this->data[i] = this->data[j];
                this->data[j] = tmp;
            }
        }
    }
}

template<typename T>
Set<T>::~Set() {
    delete[] this->data;
}