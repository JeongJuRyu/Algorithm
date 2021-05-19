#include <iostream>
using namespace std;
int n;
int answer;
void dfs(int now, int n) {
	if (now > n) return;
	else if (now == n) {
		answer++;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		dfs(now + i, n);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		answer = 0;
		cin >> n;
		dfs(0,n);
		cout << answer << '\n';
	}
	return 0;
}