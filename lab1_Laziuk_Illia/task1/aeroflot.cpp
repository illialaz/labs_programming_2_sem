#include <iostream>
using namespace std;

class Aeroflot {
  private:
    string destination;
    string flight_num;
    string plane;
    int time;
    string day;
  public:
    void Set(string&, string&, string&, int&, string&);
    string GetDestination();
    string GetNum();
    string GetPlane();
    int GetTime();
    string GetDay();
    void Show();
};

void Aeroflot:: Set(string& dest, string& num, string& plane, int& time, string& day) {
  this -> destination = dest;
  this -> flight_num = num;
  this -> plane = plane;
  this -> time = time;
  this -> day = day;
}

string Aeroflot:: GetDestination() {
  if (this -> destination.empty()) return NULL;
  return this -> destination;
}

string Aeroflot:: GetNum() {
  if (this -> flight_num.empty()) return NULL;
  return this -> flight_num;
}

string Aeroflot:: GetPlane() {
  if (this -> plane.empty()) return NULL;
  return this -> plane;
}

int Aeroflot:: GetTime() {
  return this -> time;;
}

string Aeroflot:: GetDay() {
  if(this -> day.empty()) return NULL;
  return this -> day;
}

void Aeroflot:: Show() {
  cout << "\n\n\n" << this -> destination << '\n' << this -> flight_num << '\n' << this -> plane << '\n' << this -> time / 100 << ':' << this -> time % 100 << '\n' << this -> day << "\n";
}

void print_info_for_dest(Aeroflot planes [3], string dest) {
  for(int i = 0; i < 3; i++) {
    if(planes[i].GetDestination() == dest) {
      planes[i].Show();
    }
  }
}
void print_info_for_day (Aeroflot planes [3], string day) {
  for(int i = 0; i < 3; i++) {
    if(planes[i].GetDay() == day) {
      planes[i].Show();
    }
  }
}

void print_info_for_day_and_time(Aeroflot planes [3], int time, string day) {
  for(int i = 0; i < 3; i++) {
    int tmp = planes[i].GetTime();
    if(planes[i].GetDay() == day && tmp / 100 >= time / 100) {
      if(tmp / 100 == time / 100) {
        if(tmp % 100 >= time % 100) {
          planes[i].Show();
          continue;
        }
      }
      planes[i].Show();
    }
  }
}
 
int main(void) {
  Aeroflot planes[3];
  for(int i = 0; i < 3; i++) {
    string dest, flight_num, plane, day;
    int time;
    cin >> dest >> flight_num >> plane >> day >> time;
    planes[i].Set(dest, flight_num, plane, time, day);
  }

  print_info_for_day(planes, "Monday");
  print_info_for_dest(planes, "New-York");
  int tmp = 1400;
  print_info_for_day_and_time(planes, tmp, "Monday");
  return 0;
}
