//���̳ʽ��� ó�� ���� ���, 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[2001];
int main() {
	string s;
	cin >> s;
	int sum = 0;
	int temp = 0;
	bool minus = false;
	for (int i = 0; i < s.length(); i++) {
		// +�� �ᱹ ���̳ʽ��� �� �� �̶� ������ ��� �� �־�� ��.
		if (s[i] == '+') {
			if (!minus) sum += temp;
			else sum -= temp;
			temp = 0;
		}
		else if (s[i] == '-') {
			if (!minus) {
				sum += temp;
				minus = true;
			}
			else sum -= temp;

			temp = 0;
		}
		else {
			temp *= 10;
			temp += s[i] - '0';
		}
	}
	if (minus) sum -= temp;
	else sum += temp;
	cout << sum << '\n';
	return 0;
}