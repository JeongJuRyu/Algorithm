#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> um; // hash ��� ���� unordered_map
	vector<pair<string, string>> temp; // ���߿� ����ϱ� ���� action�� id ����
	for (int i = 0; i < record.size(); i++) {
		int start = 0; // substr �޼����� ���� index ������ ���� ���� 
		vector<string> action_id_nick; // �־��� ���ڿ����� action, id, nick �Ľ�
		for (int j = 0; j < record[i].size(); j++)
		{
			if (record[i][j] == ' ') {
				action_id_nick.push_back(record[i].substr(start, j - start));
				start = j + 1;
			}
		}
		if (action_id_nick[0] != "Leave") {
			um[action_id_nick[1]] = record[i].substr(start);
		}
		else action_id_nick.push_back(record[i].substr(start));
		temp.push_back(make_pair(action_id_nick[0], action_id_nick[1]));
	}
	for (int i = 0; i < temp.size(); i++) {
		string action = temp[i].first;
		string id = temp[i].second;
		if (action == "Enter") {
			answer.push_back(um[id] + "���� ���Խ��ϴ�.");
		}
		else if (action == "Leave") {
			answer.push_back(um[id] + "���� �������ϴ�.");
		}
	}
	return answer;
}