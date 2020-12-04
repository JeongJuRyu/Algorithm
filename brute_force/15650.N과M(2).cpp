#include <iostream>
using namespace std;
bool c[10];
int a[10];
void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i<m; i++) {
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++) { // 사실 c배열 부분은 삭제해도 괜찮다.
		if (c[i]) continue;
		c[i] = true;
		a[index] = i;
		go(index + 1, i + 1, n, m);
		c[i] = false;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);
	return 0;
}