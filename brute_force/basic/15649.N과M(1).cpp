#include <iostream>
using namespace std;
bool c[10];
int a[10];

void go(int index, int m, int n) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (c[i]) continue;
		a[index] = i;
		c[i] = true;
		go(index + 1, m, n);
		c[i] = false;
	}
}

int main() {
	int m, n;
	cin >> n >> m;
	go(0, m, n);
	return 0;
}