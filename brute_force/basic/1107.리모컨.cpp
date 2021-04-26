/*��� ����� ������ �����ϰ��� �ϴ� ä�η� �̵��ϴµ� ��� Ƚ���� ���ϰ�,
�� �� �ּҰ��� ã�´�.
�������� ���� : 1. �������� ���峪�� �̵��� �� ���� ��ȣ�� ������ ��� �� �� �ִ� ��ȣ�� �̵�(���⼭ ��ư�� len ��ȯ)
2. �� �� �� ��ȣ���� �̵��Ϸ��� ��ǥ ä�� n���� �������ν�(������ ���񰪵� ���ϰ�) ++,-- ��ư�� ���� Ƚ������ ����
3. ���������� 1,2�� ���� ���ϰ� ���� ans���� ���ؼ� �� ������ ans���� �ֽ�ȭ
*/
#include <iostream> 
using namespace std;
bool broken[10]; // ���峭 ��ư ��ȣ�� ǥ���ϴ� �迭
int possible(int c) {
	if (c == 0) { // �̵��� ä���� 0�� �� ����ó��
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
		broken[x] = true; // ���峭 ��ư�� true
	}
	int ans = n - 100; // ������ ���� Ǯ������ 100�� ����
	if (ans < 0) ans = -ans; // ��ȣ ó��, �̶� ans�� ���� ++ Ȥ�� --�� ����ؼ� ���� ���� ��ư�� ���� Ƚ���̴�.

	for (int i = 0; i <= 1000000; i++) { /*�ִ밪�� �� 100�� �������� ������ �� ������ ����,
										 0~100������ ��� ����� ���� ������.*/
		int c = i;
		int len = possible(c); //���� ������ �̵��� �� �ִ� len �� ���´�
		if (len > 0) {
			int press = c - n; // ������ �ϴ� + or - ����
			if (press < 0) {
				press = -press;
			}
			if (ans > len + press) ans = len + press; 
		}
	}
	printf("%d\n", ans);
	return 0;
}