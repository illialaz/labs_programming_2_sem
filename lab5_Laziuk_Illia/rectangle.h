#include <iostream>
#include <string>
#include <cmath>

struct Point {
  double x;
  double y;
};

class Rectangle {
  protected:
    Point a;
    Point b;
  public:
    Rectangle() {
      a.x = a.y = b.x = b.y = 0;
    }
    Rectangle(const Rectangle& rect) {
      a.x = rect.a.x;
      b.x = rect.b.x;
      a.y = rect.a.y;
      b.y = rect.b.y;
    }
    Rectangle(const Point& c, const Point& d) {
      a.x = c.x;
      a.y = c.y;
      b.x = d.x;
      b.y = d.y;
    }
    Rectangle(double x1, double y1, double x2, double y2) {
      a.x = x1;
      a.y = y1;
      b.x = x2;
      b.y = y2;
    }
    ~Rectangle() {
      std::cout << "Ok\n";
    }
    void info(void) {
      double res = abs((b.x - a.x) * (b.y - a.y));
      std::cout << "(" << a.x << ", " << a.y << ") (" << b.x << ", " << b.y << ")";
      std::cout << "\nArea: " << abs((b.x - a.x) * (b.y - a.y)) << "\n";
      if(res == (b.x - a.x) * (b.x - a.x)) std::cout << "It's square\n";
    }
    void paint(void) {
      int num_of_rows = (int)(abs)((b.y - a.y) * 10);
      int num_of_columns = (int)(abs)((b.x - a.x) * 10);
      for(int i = 1; i <= num_of_rows; i++) {
        for(int j = 1; j <= num_of_columns; j++) {
          if (j == 1) {
            std::cout << "|";
            if (i == 1 || i == num_of_rows) std::cout << "-";
            else std::cout << " ";
          }

          else if (j == num_of_columns) {
            if(i == 1 || i == num_of_rows) std::cout << "-";
            else std::cout << " ";
            std::cout << "|";
            std::cout << "\n";
          }

          else if (i == 1 || i == num_of_rows) std::cout << "--";

          else std::cout << "  ";
        }
      }
    }
};

class Rect2 : public Rectangle {
  public:
    Rect2() : Rectangle() {}
    Rect2(const Rectangle& rect) : Rectangle(rect) {}
    Rect2(const Point& c, const Point& d) : Rectangle(c, d) {}
    Rect2(double x1, double y1, double x2, double y2) : Rectangle(x1, y1, x2, y2) {}
    void paint(void) {
      int num_of_rows = (int)(abs)((b.y - a.y) * 10);
      int num_of_columns = (int)(abs)((b.x - a.x) * 10);

      for(int i = 1; i <= num_of_rows; i++) {
        if(i == 1) std::cout << "(" << a.x << ", " << b.y << ")";
        else if(i == num_of_rows) std::cout << "(" << a.x << ", " << a.y << ")";
        else std::cout << "          ";
        for(int j = 1; j <= num_of_columns; j++) {
          if (j == 1) {
            std::cout << "|";
            if (i == 1 || i == num_of_rows) std::cout << "-";
            else std::cout << " ";
          }

          else if (j == num_of_columns) {
            if(i == 1 || i == num_of_rows) std::cout << "-";
            else std::cout << " ";
            std::cout << "|";
            if(i == 1) std::cout << "(" << b.x << ", " << b.y << ")";
            if(i == num_of_rows) std::cout << "(" << b.x << ", " << a.y << ")";
            std::cout << "\n";
          }

          else if (i == 1 || i == num_of_rows) std::cout << "--";

          else std::cout << "  ";
        }
      }
      double p = 2 * ((b.x - a.x) + (b.y - a.y));
      double diag = sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
      int length = (int)(p * diag);
      for(int i = 0; i < length; i++) std::cout << "_";
      std::cout << "\n";
    }
};