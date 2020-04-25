#include <string>
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
    void Show(FILE*);
};

void print_info_for_dest(Aeroflot*, string);
void print_info_for_day (Aeroflot*, string);
void print_info_for_day_and_time(Aeroflot*, int, string);
void fprint_info_for_dest(FILE*, Aeroflot*, string);
void fprint_info_for_day(FILE*, Aeroflot*, string);
void fprint_info_for_day_and_time(FILE*, Aeroflot*, int, string);
