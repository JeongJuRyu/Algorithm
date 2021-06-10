https://programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>
#include <queue>

using namespace std;
int visited[200];
int answer;
void bfs(vector<vector<int>>& computers, int target, int total_num) {
	if (visited[target]) return;
	answer++;
	visited[target] = 1;
	queue<int> q;
	q.push(target);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 0; i < total_num; i++) {
			if (computers[temp][i]) {
				if (visited[i]) continue;
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}
int solution(int n, vector<vector<int>> computers) {
	for (int i = 0; i < n; i++) {
		bfs(computers, i, n);
	}
	return answer;
}
