#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int now = 0;
	int i = 0;
	bool num_c = false;
	while (i < s.length()) {
		if (s[i] == 'S' || s[i] == 'M' || s[i] == 'U' || s[i] == 'P') {
			char flag = s[i];
			i++;
			while (s[i] - '0' == 0) i++; // 첫 자리부터 0인 경우 모두 스킵
			int temp_sum = 0;
			while (!(s[i] >= 65 && s[i] <= 92) && i<s.length()) {
				temp_sum *= 10;
				temp_sum += (s[i++] - '0');
			}
			if (flag == 'S') now -= temp_sum;
			else if (flag == 'M') now *= temp_sum;
			else if (flag == 'U') {
				if (temp_sum == 0) {
					i++;
					continue;
				}
				now /= temp_sum;
			}
				else now += temp_sum;
			}
			else if (s[i] == 'C') {
				num_c = true;
				cout << now << ' ';
				i++;
			}
			else {
				while (s[i] - '0' == 0) i++; // 첫 자리부터 0인 경우 모두 스킵
				while (!(s[i] >= 65 && s[i] <= 92)) { // 숫자부분 모두 담기
					now *= 10;
					now += (s[i++] - '0');
				}
			}
		}
		if (!num_c) {
			cout << "NO OUTPUT";
			return 0;
		}
		return 0;
	}