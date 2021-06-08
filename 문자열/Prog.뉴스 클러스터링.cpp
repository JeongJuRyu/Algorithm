#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(string str1, string str2) {
	int answer = 0;

	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

	unordered_map<string, int> mapA;
	unordered_map<string, int> mapB;

	unordered_set<string> strCollector;

	string temp;

	for (int i = 0; i < str1.size() - 1; i++) {
		string temp = str1.substr(i, 2);
		if (temp[0] >= 'A' && temp[0] <= 'Z' && temp[1] >= 'A' && temp[1] <= 'Z') {
			mapA[temp]++;
			strCollector.insert(temp);
		}
	}
	for (int i = 0; i < str2.size() - 1; i++) {
		string temp = str2.substr(i, 2);
		if (temp[0] >= 'A' && temp[0] <= 'Z' && temp[1] >= 'A' && temp[1] <= 'Z') {
			mapB[temp]++;
			strCollector.insert(temp);
		}
	}

	int common = 0;
	int sum = 0;
	for (auto str : strCollector) {
		common += min(mapA[str], mapB[str]);
		sum += max(mapA[str], mapB[str]);
	}
	if (common == 0 && sum == 0) return 65536;
	answer = 65536 * common / sum;
	return answer;
}