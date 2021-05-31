#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {
	int answer = 0;
	vector<char> friends = { 'A','C','F','J','M','N','R','T' };
	do {
		bool flag = true;
		for (int i = 0; i < data.size(); i++) {
			int temp1_index, temp2_index;
			string temp = data[i];
			char temp1 = temp[0];
			char temp2 = temp[2];
			char check_char = temp[3];
			int check_int = temp[4] - '0';
			// temp1,2 각각의 index 구함
			for (int j = 0; j < friends.size(); j++) {
				if (friends[j] == temp1) temp1_index = j;
			}
			for (int j = 0; j < friends.size(); j++) {
				if (friends[j] == temp2) temp2_index = j;
			}
			int distance = abs(temp1_index - temp2_index) - 1;
			if (check_char == '=') {
				if (distance != check_int) {
					flag = false;
					break;
				}
			}
			else if (check_char == '>') {
				if (distance <= check_int) {
					flag = false;
					break;
				}
			}
			else if (check_char == '<') {
				if (distance >= check_int) {
					flag = false;
					break;
				}
			}
			//조건문 적어주고, 하나라도 불만족시 false 및 break;   
		}
		if (flag) answer++;
	} while (next_permutation(friends.begin(), friends.end()));
	return answer;
}