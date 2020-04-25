#include <string>

class Set {
  public:
    virtual void sum(const Set&) = 0;
    virtual void mult(const Set&) = 0;
    virtual void sim_sub(const Set&) = 0;
    virtual void print() = 0;
    virtual void sort() = 0;
};

class Set_int : public Set{
  private:
    int all_elems;
    int* data;
  public:
    Set_int();
    Set_int(const Set_int&);
    void add(const int&);
    void remove(const int&);
    void operator=(const Set_int&);
    void sum(const Set&);
    void mult(const Set&);
    void sim_sub(const Set&);
    void print();
    void sort();
    ~Set_int();
};

class Set_string : public Set {
  private:
    int all_elems;
    std::string* data;
  public:
    Set_string();
    Set_string(const Set_string&);
    void add(const std::string&);
    void remove(const std::string&);
    void operator=(const Set_string&);
    void sum(const Set&);
    void mult(const Set&);
    void sim_sub(const Set&);
    void print();
    void sort();
    ~Set_string();
};