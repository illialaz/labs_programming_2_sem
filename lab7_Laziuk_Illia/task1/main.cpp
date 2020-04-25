/*
New-York
234
Boeing
Monday
1400

Sidney
435
SuperJet
Tuesday
1535

Moscow
1442
Boeing
Monday
1400
*/
#include <iostream>
using namespace std;
#include "aeroflot.h"

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

  FILE* Res = fopen("Result.txt", "w");
  fprint_info_for_day(Res, planes, "Monday");
  fprint_info_for_dest(Res, planes, "New-York");
  fprint_info_for_day_and_time(Res, planes, tmp, "Monday");
  fclose(Res);
  return 0;
}