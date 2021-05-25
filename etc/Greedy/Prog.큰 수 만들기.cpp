#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int start = 0;
	int max_index = 0;
	char max = NULL;
	for (int i = 0; i < number.size() - k; i++) {
		max = number[start];
		max_index = start;
		for (int j = start; j <= i + k; j++) {
			if (max < number[j]) {
				max = number[j];
				max_index = j;
			}
		}
		start = max_index + 1;
		answer += max;
	}
	return answer;
}