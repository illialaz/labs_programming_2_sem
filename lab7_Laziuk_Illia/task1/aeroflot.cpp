#include <iostream>
#include "aeroflot.h"
using namespace std;

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
  cout << "\n\n\n" << this -> destination << '\n' << this -> flight_num << '\n' << this -> plane << '\n' << this -> time / 100 << ':';
   if((this -> time % 100) == 0)  cout << 0 << 0;
   else cout << this -> time % 100;
   cout << '\n' << this -> day << "\n";
}

void Aeroflot::Show(FILE* Res) {
  char* tmp = new char[2];
  tmp[1] = time % 10 + '0';
  tmp[0] = (time % 100 - time % 10) / 10 + '0';
  fprintf(Res, "\n\n\n%s\n%s\n%s\n%d:%s\n%s\n", this->destination.c_str(), this->flight_num.c_str(), this->plane.c_str(), (time / 100), tmp, this->day.c_str());
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

void fprint_info_for_dest(FILE* Res, Aeroflot planes [3], string dest) {
  for(int i = 0; i < 3; i++) {
    if(planes[i].GetDestination() == dest) {
      planes[i].Show(Res);
    }
  }
}
void fprint_info_for_day (FILE* Res, Aeroflot planes [3], string day) {
  for(int i = 0; i < 3; i++) {
    if(planes[i].GetDay() == day) {
      planes[i].Show(Res);
    }
  }
}

void fprint_info_for_day_and_time(FILE* Res, Aeroflot planes [3], int time, string day) {
  for(int i = 0; i < 3; i++) {
    int tmp = planes[i].GetTime();
    if(planes[i].GetDay() == day && tmp / 100 >= time / 100) {
      if(tmp / 100 == time / 100) {
        if(tmp % 100 >= time % 100) {
          planes[i].Show(Res);
          continue;
        }
      }
      planes[i].Show(Res);
    }
  }
}
