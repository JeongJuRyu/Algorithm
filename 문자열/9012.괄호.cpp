/* 먼저, 모듈러를 활용하기 위해 x,y를 -1 해준다. 그러면 0,1,2,3.. 순으로 카잉달력 수가 증가
그 후, x값을 고정하고(즉 for문에서 변수 k 의 초기값은 x-1, 이후 m씩 더해나감) 그 k에 대해
모듈러 연산을 통해 y를 찾았다면 k+1을 출력한다. */
#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int left = 0;
		int right = 0;
		int sum = 0;
		string temp;
		cin >> temp;
		string answer;
		bool flag = false;
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == '(') {
				sum++;
			}
			else sum--;
			if (sum < 0) {
				cout << "NO" << '\n';
				flag = true;
				break;
			}
		}
		if (flag) continue;
		if (sum == 0) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

	}
	return 0;
}