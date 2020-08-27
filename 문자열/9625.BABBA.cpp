#include <iostream>
#include <string>
using namespace std;
int main() {
	int a = 1;
	int b = 0;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int temp = a;
		a = b;
		b += temp;
	}
	cout << a << ' ' << b;
	return 0;
}