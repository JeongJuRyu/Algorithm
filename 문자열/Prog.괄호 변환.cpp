#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
bool check(string p) {
	stack<int> s;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			s.push('(');
		}
		else {
			if (s.empty()) return false;
			s.pop();
		}
	}
	return true;
}
string divide(string p) {
	if (p == "") return p;
	string answer;
	int right = 0;
	int left = 0;
	string u, v;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') {
			left++;
		}
		else right++;
		u += p[i];
		if (left == right) {
			if (i == p.length() - 1) v = "";
			else v = p.substr(i + 1);
			break;
		}
	}
	if (check(u)) answer = u + divide(v);
	else {
		u = u.substr(1, u.length() - 2);
		for (int i = 0; i < u.length(); i++) {
			if (u[i] == '(') u[i] = ')';
			else u[i] = '(';
		}
		answer = '(' + divide(v) + ')' + u;
	}
	return answer;
}
string solution(string p) {
	string answer = "";
	if (check(p)) {
		return p;
	}
	int right = 0;
	int left = 0;
	string u, v;

	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') {
			left++;
		}
		else right++;
		u += p[i];
		if (left == right) {
			if (i == p.length() - 1) v = "";
			else v = p.substr(i + 1);
			break;
		}
	}
	if (check(u)) answer = u + divide(v);
	else {
		u = u.substr(1, u.length() - 2);
		for (int i = 0; i < u.length(); i++) {
			if (u[i] == '(') u[i] = ')';
			else u[i] = '(';
		}
		answer = '(' + divide(v) + ')' + u;
	}
	return answer;
}