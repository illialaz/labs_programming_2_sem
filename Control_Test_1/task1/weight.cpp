#include "weight.h"

void Weight::operator=(const Weight& weight) {
  this->kilo = weight.kilo;
  this->gramm = weight.gramm;
}

Weight Weight::operator+(const Weight& weight) {
  int tmp = this->kilo * 1000 + this->gramm + weight.kilo * 1000 + weight.gramm;
  Weight res;
  res.kilo = tmp / 1000;
  res.gramm = tmp % 1000;
  return res;
}

Weight Weight::operator-(const Weight& weight) {
  int tmp = this->kilo * 1000 + this->gramm - weight.kilo * 1000 - weight.gramm;
  Weight res;
  res.kilo = tmp / 1000;
  res.gramm = tmp % 1000;
  return res;
}

Weight Weight::operator*(double a) {
  double tmp = this->kilo * 1000 + this->gramm;
  tmp *= a;
  Weight res;
  res.kilo = tmp / 1000;
  res.gramm = (int)tmp % 1000;
  return res;
}

Weight Weight::operator/(double a) {
  double tmp = this->kilo * 1000 + this->gramm;
  tmp /= a;
  Weight res;
  res.kilo = tmp / 1000;
  res.gramm = (int)tmp % 1000;
  return res;
}

ostream& operator<<(ostream& out, const Weight& weight) {
  weight.kilo == 0 & weight.gramm < 0 ? out << '-' << weight.kilo << ',' : out << weight.kilo << ',';
  if(abs(weight.gramm) < 10) out << "00";
  if(abs(weight.gramm) < 100) out << "0";
  weight.gramm > 0 ? out << weight.gramm : out << -weight.gramm;
  out << endl;
  return out;
}

istream& operator>>(istream& in, Weight& weight) {
  in >> weight.kilo >> weight.gramm;
  return in;
}