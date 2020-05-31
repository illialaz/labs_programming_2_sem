#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	vector<int> mas;
	int size;
	cin >> size;
	int m;
	cin >> m;
	for (int i = 0; i < size; i++) {
		mas.push_back(i + 1);
	}
	int pointer = 0;
	while (size > 1) {
		pointer += m-1;
		while (pointer >= size) {
			pointer -= size;
		}
		cout << "Kill " << mas[pointer] << endl;
		mas.erase(mas.begin() + pointer);
		size--;
	}
	cout << mas[0];
	return 0;
}