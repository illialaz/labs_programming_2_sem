class Queue {
  private:
    int mas[100];
    int num_of_elems;
  public:
    Queue(void);
    Queue(const Queue&);
    void insert(void);
    void push(const int&);
    void push(const int*, const int&);
    void remove(void);
    void remove(const int&);
    bool compare(const Queue&s);
    void print(void);
    virtual~Queue(void) {};
};
