#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool visited[51];
int answer = 99999999;
string target;
bool check(string a, string b) {
	int temp = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) temp++;
	}
	if (temp <= 1) return true;
	else return false;
}
void dfs(vector<string>& words, int now, string new_target, int index) {
	if (new_target == target) {
		answer = min(answer, now);
		return;
	}
	for (int i = 0; i < words.size(); i++) {
		if (!check(words[i], new_target) || visited[i]) continue; //2 글자 이상 다른 경우 continue;
		visited[i] = true;
		dfs(words, now + 1, words[i], i);
		visited[i] = false;
	}
}

int solution(string begin, string target_main, vector<string> words) {
	if (find(words.begin(), words.end(), target_main) == words.end()) return 0;
	target = target_main;
	for (int i = 0; i < words.size(); i++) {
		if (!check(words[i], begin)) continue;
		visited[i] = true;
		dfs(words, 1, words[i], i);
		visited[i] = false;
	}
	return answer;
}