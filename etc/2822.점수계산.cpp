#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<pair<int,int>> v;
	vector<int> num;
	int sum = 0;
	for (int i = 1; i <= 8; i++) {
		int temp;
		cin >> temp;
		v.push_back(make_pair(temp,i));
	}
	sort(v.begin(), v.end());
	for (int i = 7; i >= 3; i--) {
		sum += v[i].first;
		num.push_back(v[i].second);
	}
	cout << sum << '\n';
	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) cout << num[i] << ' ';
	return 0;
}