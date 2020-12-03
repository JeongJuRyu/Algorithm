/*모든 경우의 수에서 접근하고자 하는 채널로 이동하는데 드는 횟수를 구하고,
그 중 최소값을 찾는다.
세부적인 과정 : 1. 리모컨이 고장나서 이동할 수 없는 번호를 제외한 모든 갈 수 있는 번호로 이동(여기서 버튼수 len 반환)
2. 그 후 각 번호에서 이동하려는 목표 채널 n값을 빼줌으로써(음수면 절댓값도 취하고) ++,-- 버튼을 누른 횟수까지 구함
3. 마지막으로 1,2의 값을 더하고 이전 ans값과 비교해서 더 작으면 ans값을 최신화
*/
#include <iostream> 
using namespace std;
bool broken[10]; // 고장난 버튼 번호를 표시하는 배열
int possible(int c) {
	if (c == 0) { // 이동할 채널이 0일 때 예외처리
		if (broken[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (c > 0) {
		if (broken[c % 10]) return 0;
		len += 1;
		c /= 10;
	}
	return len;
}
int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) { 
		int x;
		cin >> x;
		broken[x] = true; // 고장난 버튼에 true
	}
	int ans = n - 100; // 문제를 쉽게 풀기위해 100을 뺀다
	if (ans < 0) ans = -ans; // 부호 처리, 이때 ans의 값은 ++ 혹은 --만 사용해서 갔을 때의 버튼을 누른 횟수이다.

	for (int i = 0; i <= 1000000; i++) { /*최대값은 약 100만 정도에서 결정이 될 것으로 예상,
										 0~100만까지 모든 경우의 수를 따진다.*/
		int c = i;
		int len = possible(c); //가장 가까이 이동할 수 있는 len 값 얻어온다
		if (len > 0) {
			int press = c - n; // 눌러야 하는 + or - 갯수
			if (press < 0) {
				press = -press;
			}
			if (ans > len + press) ans = len + press; 
		}
	}
	printf("%d\n", ans);
	return 0;
}