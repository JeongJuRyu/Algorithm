#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> um; // hash 사용 위한 unordered_map
	vector<pair<string, string>> temp; // 나중에 사용하기 위한 action과 id 저장
	for (int i = 0; i < record.size(); i++) {
		int start = 0; // substr 메서드의 시작 index 저장을 위한 변수 
		vector<string> action_id_nick; // 주어진 문자열에서 action, id, nick 파싱
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
			answer.push_back(um[id] + "님이 들어왔습니다.");
		}
		else if (action == "Leave") {
			answer.push_back(um[id] + "님이 나갔습니다.");
		}
	}
	return answer;
}