#include <string>

using namespace std;

int solution(string s) {
	int answer = s.length();

	if (s.length() == 1)
		return 1;

	for (int i = 1; i <= s.length() / 2; i++) { //�� ���� ����
		int count = 1;
		string compare_string = s.substr(0, i);
		string temp_string, temp_answer_string;

		for (int j = i; j < s.length(); j += i) { //ó������ �� ���ϱ�
			temp_string = s.substr(j, i);

			if (compare_string == temp_string)  //�� ���ڰ� ������ count ����
				count++;
			else {
				if (count == 1) {
					temp_answer_string += compare_string;
					compare_string = temp_string;
				}
				else {
					temp_answer_string = temp_answer_string + to_string(count) + compare_string;
					compare_string = temp_string;
					count = 1;
				}
			}

			if (j + i >= s.length()) {  //�������� substr������ �ʰ��� ���
				if (count != 1) {
					temp_answer_string = temp_answer_string + to_string(count) + compare_string;
					break;
				}
				else {
					temp_answer_string += s.substr(j);
					break;
				}
			}
		}
		answer = (answer > temp_answer_string.length()) ? temp_answer_string.length() : answer;
	}

	return answer;
}