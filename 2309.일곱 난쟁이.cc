/* 아홉 명 중에 일곱을 고르는 것은 아홉 명 중에 둘을 고르는 것 과 같다
이중 for문을 통해 sum에서 */

#include <iostream>
#include <algorithm>
using namespace std;
int a[9];
int n = 9;
int main() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sum - a[i] - a[j] == 100) {
				for (int k = 0; k < n; k++) {
					if (i == k || j == k) continue; // i번째, j번째는 포함시키지 않으므로 출력 안함
					cout << a[k] << '\n';
				}
				return 0;
			}
		}
	}
	return 0;
}