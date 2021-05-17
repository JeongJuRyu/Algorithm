#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector <string> a[51];

int main() {
	int num;
	cin >> num;
	string temp;
	for (int i = 1; i <= num; i++) {
		bool check = false;
		cin >> temp;
		int num_gj = temp.length();
		for (int j = 0; j < a[num_gj].size(); j++) {
			if (a[num_gj][j] == temp) {
				check = true;
				break;
			}
		}
		if (!check) a[num_gj].push_back(temp);
	}
	for (int i = 1; i <= 50; i++) {
		sort(a[i].begin(), a[i].end());
	}
	for (int i = 1; i <= 50; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			cout << a[i][j] << '\n';
		}
	}
	return 0;
}