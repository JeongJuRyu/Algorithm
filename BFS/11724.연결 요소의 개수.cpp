#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visited[1001];

void bfs() {
	
}
int main() {
	int answer = 0;
	int n, m;
	cin >> n >> m;
	queue<int> q;
	vector<int> a[1001];
	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		a[temp1].push_back(temp2);
		a[temp2].push_back(temp1);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		answer++;
		q.push(i);
		while (!q.empty()) {
			int current = q.front();
			q.pop();
			for (int j = 0; j < a[current].size(); j++) {
				int next = a[current][j];
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
			}
		}
	}
	cout << answer;
	return 0;
}