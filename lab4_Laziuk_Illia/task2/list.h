using namespace std;
template <typename T>
class List {
  private:
    struct Node{
      T data;
      Node* next;
      Node* prev;
    };
    Node* head;
    Node* cur;
  public:
    List(void) {
      this->head = new Node;
      this->head->next = this->head;
      this->cur = this->head;
      this->head->prev = NULL;
    }
    ~List(void) {
      Node* tmp = this->head;
      while(tmp) {
        Node*p = tmp;
        delete tmp;
        tmp = p->next;
      }
    }
    void addFirst(const T& data) {
      this->head->data = data;
      this->head->next = NULL;
    }
    void add(const T& data) {
      if(this->head->next == this->head) return addFirst(data);

      struct Node* tmp = new Node();
      tmp->data = data;
      tmp->next = this->cur->next;
      tmp->prev = this->cur;
      if(this->cur->next) this->cur->next->prev = tmp;
      this->cur->next = tmp;
    }
    T get(void) {
      T res;
      if(!this->head->next) {
        res = this->head->data;
        delete head;
        this->head = new Node;
        this->head->next = this->head;
        this->cur = this->head;
        this->head->prev = NULL;
        return res;
      }
      struct Node* tmp = this->cur;
      if(!(tmp || tmp->next)) this->moveBack();
      if(!(tmp || tmp->prev)) this->moveForward();
      if(this->cur->prev) this->cur->prev->next = this->cur->next;
      if(this->cur->next) this->cur->next->prev = this->cur->prev;
      this->cur = this->cur->next;
      res = tmp->data;
      if(tmp == head) head = head->next;
      delete tmp;
      return res;
    }
    void moveForward(void) {
      if(this->cur->next) this->cur = this->cur->next;
    }
    void moveBack(void) {
      if(this->cur->prev) this->cur = this->cur->prev;
    }
    T pick(void) {
      return this->cur->data;
    }
    void print(void) {
      struct Node* tmp = this->head;
    while(tmp) {
      cout << tmp->data;
      if(tmp == this->cur) cout << "\t<-";
        cout << endl;
        tmp = tmp->next;
      }
    }
};

class Student {
  private:
    int grade;
    char symbol;
    double mark;
    string name;
  public:
    friend ostream& operator<<(ostream& out, const Student& student) {
      out << student.name << " " << student.grade << " " << student.symbol << " " << student.mark << endl;
      return out;
    }
    friend istream& operator>>(istream& in, Student& student) {
      in >> student.name >> student.grade >> student.symbol >> student.mark;
      return in;
    }
};

void printmenu(void) {
  printf("1.Add\n2.Remove\n3.Move Forward\n4.Move Back\n5.Pick\n6.Print\n7.Print Menu\n0.End\n");
}
