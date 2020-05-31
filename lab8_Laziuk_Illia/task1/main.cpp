#include<fstream>
#include<iostream>
#include<vector>
#include<ctype.h>
#include<algorithm>
using namespace std;


struct town_rest {
	string town = "";
	vector< pair<string,int> > rest;
};

bool compareStr(town_rest a, town_rest b) {
	return (a.town < b.town);
}

int main(void) {
	vector<town_rest> mas;
	int max_rest = 0;
	ifstream file("info.txt");
	if (!file) return -1;
	while (!file.eof()) {
		town_rest tmp;
		char* buf = new char[100];
		file.getline(buf, 99);
		if (strcmp(buf, "")) {
			for (int i = 0; i < 99; i++) {
				buf[i] = tolower(buf[i]);
			}
			char* pch = strtok(buf, " ,.");
			pch[0] = toupper(pch[0]);
			tmp.town = pch;
			pch = strtok(NULL, " ,.");
			pch[0] = toupper(pch[0]);
			pair<string, int> tmp2;
			tmp2.first = pch;
			pch = strtok(NULL, " ,."); 
			tmp2.second = atoi(pch);
			tmp.rest.push_back(tmp2);
			bool ch = true;
			for (int i = 0; i < mas.size(); i++) {
				if (tmp.town == mas[i].town && ch) {
					ch = false;
					mas[i].rest.push_back(tmp2);
				}
			}
			if (ch) {
				mas.push_back(tmp);
			}
		}
	}
	
	sort(mas.begin(), mas.end(), compareStr);

	for (int i = 0; i < mas.size(); i++) {		
		cout << mas[i].town << ":" << endl;
		if (mas[i].rest.size() > max_rest) {
			max_rest = mas[i].rest.size();
		}
			for (int j = 0; j < mas[i].rest.size(); j++) {
				cout << mas[i].rest[j].first << " " << mas[i].rest[j].second << endl;
			}
			cout << endl;		
	}

	cout << endl;

	int a;
	cout << "Enter num of restaurants\n";
	cin >> a;
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].rest.size() >= a) {
			cout << mas[i].town << ":" << endl;
			for (int j = 0; j < mas[i].rest.size(); j++) {
				cout << mas[i].rest[j].first << " " << mas[i].rest[j].second << endl;
			}
			cout << endl;
		}
	}
	cout << endl;

	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].rest.size() == max_rest) {
			cout << mas[i].town << ":" << endl;
			for (int j = 0; j < mas[i].rest.size(); j++) {
				cout << mas[i].rest[j].first << " " << mas[i].rest[j].second << endl;
			}
			cout << endl;
		}
	}
	cout << endl;

	string twn;
	string rst;
	cout << "Enter name of town you want to change\n";
	cin >> twn;
	for (int i = 0; i < twn.length(); i++) {
		twn[i] = tolower(twn[i]);
	}
	twn[0] = toupper(twn[0]);

	cout << "Enter name of restaurant you want to change\n";
	cin >> rst;
	for (int i = 0; i < rst.length(); i++) {
		rst[i] = tolower(rst[i]);
	}
	rst[0] = toupper(rst[0]);

	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].town == twn) {
			for (int j = 0; j < mas[i].rest.size(); j++) {
				if (mas[i].rest[j].first == rst) {
					cout << "New name: ";
					cin >> mas[i].rest[j].first;
					break;
				}
			}
			break;
		}		
	}
	cout << endl;
	cout << endl << endl;
	for (int i = 0; i < mas.size(); i++) {
		
			cout << mas[i].town << ":" << endl;
			for (int j = 0; j < mas[i].rest.size(); j++) {
				cout << mas[i].rest[j].first << " " << mas[i].rest[j].second << endl;
			}
			cout << endl;
		
	}
	return 0;
}