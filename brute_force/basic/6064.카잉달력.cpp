/* ����, ��ⷯ�� Ȱ���ϱ� ���� x,y�� -1 ���ش�. �׷��� 0,1,2,3.. ������ ī�״޷� ���� ����
�� ��, x���� �����ϰ�(�� for������ ���� k �� �ʱⰪ�� x-1, ���� m�� ���س���) �� k�� ����
��ⷯ ������ ���� y�� ã�Ҵٸ� k+1�� ����Ѵ�. */
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