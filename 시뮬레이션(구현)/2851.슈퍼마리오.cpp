#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int sum[10];
	vector<int> v(10);
	for (int i = 0; i < 10; i++) {
		cin >> v[i];
	}
	int sum_of_mash = 0;
	for (int i = 0; i < 10; i++) {
		sum_of_mash += v[i];
		sum[i] = sum_of_mash - 100;
	}
	int answer_index = 0;
	int min_abs = abs(sum[0]);
	for (int i = 1; i < 10; i++) {
		if (min_abs >= abs(sum[i])) {
			min_abs = abs(sum[i]);
			answer_index = i;
		}
	}
	cout << sum[answer_index] + 100 << '\n';
	return 0;
}