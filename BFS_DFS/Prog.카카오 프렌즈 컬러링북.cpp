// ���� ���� solution ������ �ʱ�ȭ �� �־�� �����
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int m, n;
bool visited[100][100];
int number_of_area;
int max_size_of_one_area;
int whall_picture[100][100];

void BFS(int i, int j) {
	if (visited[i][j] || whall_picture[i][j] == 0) return;
	queue<pair<int, int>> q;
	number_of_area++;
	int temp_size = 1;
	visited[i][j] = true;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx<0 || nx >= m || ny < 0 || ny >= n) continue;
			if (whall_picture[nx][ny] != whall_picture[x][y]) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			temp_size++;
			q.push(make_pair(nx, ny));
		}
	}
	//max_size ���� �˻�
	max_size_of_one_area = max(max_size_of_one_area, temp_size);
}
// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int _m, int _n, vector<vector<int>> picture) {
	number_of_area = 0;
	max_size_of_one_area = 0;
	m = _m; n = _n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			whall_picture[i][j] = picture[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			BFS(i, j);
		}
	}
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}