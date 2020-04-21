#include <iostream>
using namespace std;
class Weight {
  private:
    int kilo;
    int gramm;
  public:
    void operator=(const Weight&);
    Weight operator+(const Weight&);
    Weight operator-(const Weight&);
    Weight operator*(double);
    Weight operator/(double);
    friend ostream& operator<<(ostream&, const Weight&);
    friend istream& operator>>(istream&, Weight&);
};