/* ����, ��ⷯ�� Ȱ���ϱ� ���� x,y�� -1 ���ش�. �׷��� 0,1,2,3.. ������ ī�״޷� ���� ����
�� ��, x���� �����ϰ�(�� for������ ���� k �� �ʱⰪ�� x-1, ���� m�� ���س���) �� k�� ����
��ⷯ ������ ���� y�� ã�Ҵٸ� k+1�� ����Ѵ�. */
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