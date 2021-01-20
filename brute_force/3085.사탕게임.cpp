#include <string>
#include <vector>
bool arr[9999999];
using namespace std;
int answer, n;
bool dfs(vector<int>& v, int num, int now_digit)){
if (v.empty()) {
	if (!arr[num]) answer++;
}
for (int i = 0; i<v.size(); i++) {
	int temp_num = v.push_back();
	dfs(v, num += num * now_digit, now_digit * 10);
	v.push(temp_num);
}
}
int solution(string numbers) {
	vector<int> v;
	for (int i = 0; i < numbers.length(); i++) {
		v.push_back(numbers[i] - '0');
	}
	n = v.size();
	for (int i = 1; i*i <= 9999999; i++) {
		if (n == 1) continue;
		if (!arr[i]) {
			for (int j = i * i; j <= n; j += i) {
				arr[j] = true;
			}
		}
	}
	dfs(v, 0, 1)
		int answer = 0;
	return answer;
}

int main() {
	cout << solution('1234') << '\n';
}