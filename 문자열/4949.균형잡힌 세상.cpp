#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	while (1) {
		string s;
		getline(cin, s);
		if (s.length() == 1 && s[0] == '.') break;
		stack<char> small;
		stack<char> big;
		stack<char> last_char;
		bool flag = false;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				small.push(1);
				last_char.push('(');
			}
			else if (s[i] == ')') {
				if (small.empty() || last_char.top() != '(') {
					flag = true;
					break;
				}
				else {
					last_char.pop();
					small.pop();
				}
			}
			if (s[i] == '[') {
				big.push(1);
				last_char.push('[');
			}
			else if (s[i] == ']') {
				if (big.empty() || last_char.top() != '[') {
					flag = true;
					break;
				}
				else {
					last_char.pop();
					big.pop();
				}
			}
			
		}
		if ((small.empty() && big.empty()) && flag == false) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	return 0;

}