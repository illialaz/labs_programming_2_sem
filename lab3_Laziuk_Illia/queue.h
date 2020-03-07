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
    int getnum(void);
    const int* getmas(void);
    bool compare(const Queue&);
    void print(void);
    bool operator==(const Queue&);
    bool operator!=(const Queue&);
    Queue operator+(const Queue&);
    //Queue operator-(const Queue&);
    void operator=(const Queue&);
    void operator+=(const Queue&);
    friend std::ostream& operator<<(std::ostream&, const Queue&);
    friend std::istream& operator>>(std::istream&, Queue&);
    virtual~Queue(void) {};
};
