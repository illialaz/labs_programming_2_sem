#include "rectangle.h"

int main(void) {
  Rectangle a(1.5, 1.1, 3.3, 4.2);
  Rect2 b(a);
  a.paint();
  a.info();
  b.paint();
  b.info();
  return 0;
}