struct Node {
    char* firstname;
    char* lastname;
    char* patronimic;
    int age;
    struct Node* next;
    struct Node* previous;
};

class Ring {
private:
    struct Node* head;
public:
    Ring(void) {
        head = new Node;
        head->firstname = NULL;
        head->lastname = NULL;
        head->patronimic = NULL;
        head->age = 0;
        head->previous = head->next = head;
    }
    void addFirst(const char*, const char*, const char*, const int&);
    void addFront(const char*, const char*, const char*, const int&);
    void addBack(const char*, const char*, const char*, const int&);
    void addAfter(const int&, const char*, const char*, const char*, const int&);
    void addBefore(const int&, const char*, const char*, const char*, const int&);
    void replace(void);
    void replace(const int&);
    void remove(void);
    void removeAfter(const int& num);
    void removeBefore(const int& num);
    void print(void);
    virtual ~Ring(void) {
        if(!head) return;

        Node *p = head->next;
        while (p != head) {
            Node *next = p->next;
            delete p->firstname;
            delete p->lastname;
            delete p->patronimic;
            delete p;
            p = next;
        }
        delete head;
    }
};

void printIntroduction(void);

void printMenu(void);
