#include <iostream>
#include <string>
using namespace std;
#include "set.h"

int main(void) {
    Set<int> a, b, c, d, e;
    FILE* out = fopen("data1.txt", "r");
    if(!out) {
        for(int i = 1; i < 10; i++) a.add(i);
        for(int i = 3; i < 12; i++) b.add(i);
    }
    else {
        char str[100];
        char res[100];
        char res1[100];
        char res2[100];
        int num1, num2;
        cout << "Which string from file do you want to use for your first set?\n";
        cin >> num1;
        cout << "Which string from file do you want to use for your second set?\n";
        cin >> num2;
        char n, m;
        while(fgets(str, 80, out)) {
            if(str[0] == '%') {
                fgets(res, 80, out);
                if(str[1] == num1 + '0') { strcpy(res1, res); n = 1; }
                if(str[1] == num2 + '0') { strcpy(res2, res); m = 1; }
            }
        }
        if(n != 1) strcpy(res1, res);
        if(m != 1) strcpy(res2, res);
        char* p = new char[100];
        p = strtok(res1, " ");
        int r = atoi(p);
        for(int i = 0; i < r; i++) {
            p = strtok(NULL, " ");
            a.add(atoi(p));
        }
        p = strtok(res2, " ");
        r = atoi(p);
        for(int i = 0; i < r; i++) {
            p = strtok(NULL, " ");
            b.add(atoi(p));
        }
    }
    fclose(out);


    c = a + b;
    d = a * b;
    e = a - b;
    a.print();
    b.print();
    c.print();
    d.print();
    e.print();
    return 0;
}

// int main(void) {
//     Set<string> a, b, c, d, e;
//     FILE* out = fopen("data2.txt", "r");
//     if(!out) {
//         for(int i = 1; i < 10; i++) a.add("Hello");
//         for(int i = 3; i < 12; i++) b.add("Bye");
//     }
//     else {
//         char str[100];
//         char res[100];
//         char res1[100];
//         char res2[100];
//         int num1, num2;
//         cout << "Which string from file do you want to use for your first set?\n";
//         cin >> num1;
//         cout << "Which string from file do you want to use for your second set?\n";
//         cin >> num2;
//         char n, m;
//         while(fgets(str, 80, out)) {
//             if(str[0] == '%') {
//                 fgets(res, 80, out);
//                 if(str[1] == num1 + '0') { strcpy(res1, res); n = 1; }
//                 if(str[1] == num2 + '0') { strcpy(res2, res); m = 1; }
//             }
//         }
//         if(n != 1) strcpy(res1, res);
//         if(m != 1) strcpy(res2, res);
//         char* p = new char[100];
//         p = strtok(res1, " \n");
//         int r = atoi(p);
//         for(int i = 0; i < r; i++) {
//             p = strtok(NULL, " \n");
//             string t(p);
//             a.add(t);
//         }
//         p = strtok(res2, " \n");
//         r = atoi(p);
//         for(int i = 0; i < r; i++) {
//             p = strtok(NULL, " \n");
//             string t(p);
//             b.add(t);
//         }
//     }
//     fclose(out);


//     c = a + b;
//     d = a * b;
//     e = a - b;
//     a.print();
//     b.print();
//     c.print();
//     d.print();
//     e.print();
//     return 0;
// }