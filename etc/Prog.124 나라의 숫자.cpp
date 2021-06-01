#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
	string arr[3] = { "4","1","2" };
	string answer = "";
	int index;
	while (n>0)
	{
		index = n % 3;
		if (index == 0)
		{
			n = n - 1;
		}
		n = n / 3;
		answer = arr[index] + answer;
	}
	return answer;
}