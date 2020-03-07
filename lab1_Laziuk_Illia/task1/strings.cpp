#include <iostream>
#include <string> 
using namespace std;

int main() {
// различные способы инициализации
  string str1("first string");
  string str2(str1);
  string str3(5, '#'); // #####
  string str4(str1, 6, 6); // string
  string str5(str2.begin(), str2.begin() + 5); // first
  cout << str1 << endl;
  cout << str2 << endl;
  cout << str3 << endl;
  cout << str4 << endl;
  cout << str5 << endl;
  // оператор присваивания 
  string str6 = str4;
  str4.clear(); // очистка строки
  int len = str6.length(); // len = str6.size();
  cout << "Length of string is : " << len << endl;
  char ch = str6.at(2); // ch = str6[2];
  cout << "third character of string is : " << ch << endl;
  char ch_f = str6.front(); // ch_f = str6[0];
  char ch_b = str6.back(); // ch_b = str6[str6.length() - 1];
  cout << "First char is : " << ch_f << ", Last char is : " << ch_b << endl;
  const char* charstr = str6.c_str();
  printf("%s\n", charstr);
  str6.append(" extension"); // str6 += " extension"
  str4.append(str6, 0, 6); // string
  cout << str6 << endl;
  cout << str4 << endl;
  if (str6.find(str4) != string::npos)
  cout << "str4 found in str6 at " << str6.find(str4) << " pos" << endl; // поиск строки в строке
  else
  cout << "str4 not found in str6" << endl;
  cout << str6.substr(7, 3) << endl; // выводит 3 символа начиная с седьмого
  cout << str6.substr(7) << endl; // выводит все символы начиная с седьмого
  str6.erase(7, 4); // вырезает из строки 4 символа начиная с седьмого
  cout << str6 << endl;
  str6.erase(str6.begin() + 5, str6.end() - 3);
  cout << str6 << endl;
  str6 = "This is a examples";
  str6.replace(2, 7, "ese are test"); // замена элементов со 2 по 7 на сроку
  cout << str6 << endl;
  return 0;
}



/*_____________________________*/
#include <iostream>
#include <string>
using namespace std;

int main() {
string str("GeeksforGeeks"); string str1("GeeksforGeeks");
if (str.compare(str1) == 0) // сравнение строк
cout << "Strings are equal\n";
else
cout << "Strings are unequal\n";
return 0;
}




/*_____________________________*/
#include <iostream>
#include <string>
using namespace std;

int main() {
string str("The Geeks for Geeks");

cout << "First occurrence of \"Geeks\" starts from : "; cout << str.find("Geeks") << endl; // поиск всего слова сначала 
cout << "First occurrence of character from \"reef\" is at : "; cout << str.find_first_of("reef") << endl; // поиск любого из элементов с начала
cout << "Last occurrence of character from \"reef\" is at : "; cout << str.find_last_of("reef") << endl; // поиск любого из элементов с конца
cout << "Last occurrence of \"Geeks\" starts from : "; cout << str.rfind("Geeks") << endl; // поиск слова с конца
return 0;
}




/*_____________________________*/
  #include <iostream>
  #include <string>
  using namespace std;

  int main() {
  string str("Geeksfor");
  cout << str << endl;
  str.insert(8, "Geeks"); // Вставка строки в конец
  cout << str << endl;
  return 0;
} 
/*_____________________________*/




#include <iostream>
#include <string>
using namespace std;

int main() {
string str("GeeksforGeeks");
// clearing string 
str.clear();
// Checking if string is empty 
(str.empty()) ?
  cout << "String is empty" << endl:
  cout << "String is not empty" << endl;
return 0;
}
/*_____________________________*/




#include <iostream>
#include <string>
using namespace std;

void reverseStr(string& str) {
  int n = str.length();
  for (int i = 0; i < n / 2; i++) swap(str[i], str[n - i - 1]);
}
int main() {
  string str = "geeksforgeeks";
  reverseStr(str); // переворачивает строку
  cout << str;
  return 0;
}
/*_____________________________*/




#include <iostream>
#include <string>
using namespace std;

int main() {
  string str = "geeksforgeeks";
  reverse(str.begin(), str.end()); // переворачивает строку с начала до конца
  cout << str;
 return 0;
} /*_____________________________*/




#include <iostream>
#include <string>
using namespace std;
int main() {
  setlocale(LC_ALL, "rus");
  string myStr;
  cout << "Введите строку состоящую\n"
  "из нескольких слов,\n"
  "разделенных пробелами:\n";
  cin >> myStr; // считает тольео первое слово
  cout << myStr << endl;
  string S;
  while (!cin.eof() && cin.get() != '\n') { // считает всю строку
    cin >> S;
    myStr += ' ' + S;
  }
  cout << myStr << endl;
  return 0;
}