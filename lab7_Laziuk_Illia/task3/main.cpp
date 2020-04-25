#include <iostream>
#include <fstream>
#include <string>
#include "set.h"
using namespace std;

int main(void) {
  Set_int a, b, c;
  string bin;
  ifstream TextIn("text1.txt");
  if(TextIn) {
  ofstream BinOut("text1.bin", ios::out|ios::binary);
    if (BinOut) {
      while (getline(TextIn, bin)) {
        bin += '\n';
        char str[100];
        strcpy(str, bin.c_str());
        BinOut.write(str, (strlen(str)));
      }
    }
  }
  TextIn.close();

  ifstream BinIn("text1.bin", ios::in | ios::binary);
  if(BinIn) {
    char str[100];
    char res[100];
    char res1[100];
    char res2[100];
    char res3[100];
    int num1, num2, num3;
    cout << "Which string from file do you want to use for your first set?\n";
    cin >> num1;
    cout << "Which string from file do you want to use for your second set?\n";
    cin >> num2;
    cout << "Which string from file do you want to use for your third set?\n";
    cin >> num3;
    char n = 0, m = 0, k = 0;
    BinIn.read(str, 1);
    while(BinIn) {
      if(str[0] == '%') {
        string temp_res;
        BinIn.read(str, 1);
        while(str[0] != '\n') {
          temp_res += str[0];
          BinIn.read(str, 1);
        }
        int num = stoi(temp_res);
        temp_res = "";
        BinIn.read(str, 1);
        while(str[0] != '\n') {
          temp_res += str[0];
          BinIn.read(str, 1);
        }
        strcpy(res, temp_res.c_str());
        if(num == num1) { strcpy(res1, res); n = 1; }
        if(num == num2) { strcpy(res2, res); m = 1; }
        if(num ==  num3) { strcpy(res3, res); k = 1; }
        BinIn.read(str, 1);
      }
    }
    if(n != 1) strcpy(res1, res);
    if(m != 1) strcpy(res2, res);
    if(k != 1) strcpy(res3, res);
    char* p = new char[100];
    p = strtok(res1, " \n");
    int r = atoi(p);
    for(int i = 0; i < r; i++) {
      p = strtok(NULL, " \n");
      a.add(atoi(p));
    }
    p = strtok(res2, " \n");
    r = atoi(p);
    for(int i = 0; i < r; i++) {
      p = strtok(NULL, " \n");
      b.add(atoi(p));
    }
    p = strtok(res3, " \n");
    r = atoi(p);
    for(int i = 0; i < r; i++) {
      p = strtok(NULL, " \n");
      c.add(atoi(p));
    }
  }
  else {
    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5); // 12345
    b.add(3);
    b.add(4);
    b.add(7); // 347
    c.add(0);
    c.add(3);
    c.add(5);
    c.add(6); // 0356
  }
  a.sum(b);
  a.print();
  c.sim_sub(a); 
  c.print();
  b.mult(c); 
  b.print();
  return 0;
}

// int main() {
//   Set_string a, b, c;
//   string bin;
//   int* Scores = new int[5];
//   int NameLen;
//   ifstream TextIn("text2.txt");
//   if(TextIn) {
//     ofstream BinOut("text2.bin", ios::out|ios::binary);
//     if (BinOut) {
//       while (getline(TextIn, bin)) {
//         bin += '\n';
//         char str[100];
//         strcpy(str, bin.c_str());
//         BinOut.write(str, (strlen(str)));
//       } 
//     }
//   }
//   TextIn.close();

//   ifstream BinIn("text2.bin", ios::in | ios::binary);
//   if(BinIn) {
//   char* cName = new char[100];
//   char str[100];
//   char res[100];
//   char res1[100];
//   char res2[100];
//   char res3[100];
//   int num1, num2, num3;
//   cout << "Which string from file do you want to use for your first set?\n";
//   cin >> num1;
//   cout << "Which string from file do you want to use for your second set?\n";
//   cin >> num2;
//   cout << "Which string from file do you want to use for your third set?\n";
//   cin >> num3;
//   char n = 0, m = 0, k = 0;
//   BinIn.read(str, 1);
//   while(BinIn) {
//     if(str[0] == '%') {
//       string temp_res;
//       BinIn.read(str, 1);
//       while(str[0] != '\n') {
//         temp_res += str[0];
//         BinIn.read(str, 1);
//       }
//       int num = stoi(temp_res);
//       temp_res = "";
//       BinIn.read(str, 1);
//       while(str[0] != '\n') {
//         temp_res += str[0];
//         BinIn.read(str, 1);
//       }
//       strcpy(res, temp_res.c_str());
//       if(num == num1) { strcpy(res1, res); n = 1; }
//       if(num == num2) { strcpy(res2, res); m = 1; }
//       if(num ==  num3) { strcpy(res3, res); k = 1; }
//       BinIn.read(str, 1);
//     }
//     if(n != 1) strcpy(res1, res);
//     if(m != 1) strcpy(res2, res);
//     if(k != 1) strcpy(res3, res);
//     char* p = new char[100];
//     p = strtok(res1, " \n");
//     int r = atoi(p);
//     for(int i = 0; i < r; i++) {
//       p = strtok(NULL, " \n");
//       a.add(p);
//     }
//     p = strtok(res2, " \n");
//     r = atoi(p);
//     for(int i = 0; i < r; i++) {
//       p = strtok(NULL, " \n");
//       b.add(p);
//     }
//     p = strtok(res3, " \n");
//     r = atoi(p);
//     for(int i = 0; i < r; i++) {
//       p = strtok(NULL, " \n");
//       c.add(p);
//     }
//   }
//   else {
//     a.add("a");
//     a.add("b");
//     a.add("c");
//     a.add("d");
//     a.add("e"); // abcde
//     b.add("a");
//     b.add("s");
//     b.add("d"); // asd
//     c.add("q");
//     c.add("e");
//     c.add("s");
//     c.add("g"); // qesg
//   }
//   a.sum(b); // abcde asd
//   a.print();
//   c.sim_sub(a); // qesg abcdes
//   c.print();
//   b.mult(c); // asd abcdqg
//   b.print();
//   return 0;
// }
