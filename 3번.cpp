/* 먼저, 모듈러를 활용하기 위해 x,y를 -1 해준다. 그러면 0,1,2,3.. 순으로 카잉달력 수가 증가
그 후, x값을 고정하고(즉 for문에서 변수 k 의 초기값은 x-1, 이후 m씩 더해나감) 그 k에 대해
모듈러 연산을 통해 y를 찾았다면 k+1을 출력한다. */
#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x -= 1; // 나머지 연산의 편의를 위해 1을 뺌
		y -= 1;
		bool ok = false;
		for (int k = x; k < (n*m); k += m) { // 모든 경우의 수를 따질 필요가 없으므로 m을 더해 나가면서
			if (k%n == y) {                  // 그 순서쌍만 비교한다. k%n 이 찾던 y값과 일치하면
				cout << k + 1 << '\n';       // k에 + 1 해서 원래대로 돌리고 출력한다.
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << -1 << '\n';
		}
	}
	return 0;
}