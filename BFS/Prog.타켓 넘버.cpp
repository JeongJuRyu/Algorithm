#include <string>
#include <vector>

using namespace std;
int answer, total_num;
int target_problem;
void bfs(vector <int>& numbers, int total, int now) {
	if (now == total_num) {
		if (total == target_problem) answer++;
		return;
	}
	bfs(numbers, total + numbers[now], now + 1);
	bfs(numbers, total - numbers[now], now + 1);
}
int solution(vector<int> numbers, int target) {
	target_problem = target;
	total_num = numbers.size();
	bfs(numbers, 0, 0);
	return answer;
}