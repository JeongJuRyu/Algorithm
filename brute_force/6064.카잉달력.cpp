/* 먼저, 모듈러를 활용하기 위해 x,y를 -1 해준다. 그러면 0,1,2,3.. 순으로 카잉달력 수가 증가
그 후, x값을 고정하고(즉 for문에서 변수 k 의 초기값은 x-1, 이후 m씩 더해나감) 그 k에 대해
모듈러 연산을 통해 y를 찾았다면 k+1을 출력한다. */
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int answer = 9;
	if (n <= 9) {
		cout << n << '\n';
		return 0;
	}
	int num = 10;
	int digit = 2;
	while (!(n >= num && n < num*10)) {
		answer += 9 * num * digit;
		num *= 10;
		digit += 1;
	}
	answer += (n - num + 1)*digit;
	cout << answer << '\n';
	return 0;
}