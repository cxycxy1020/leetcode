#include <iostream>
#include <climits>
#include <string>
using namespace std;

int myAtoi(string s)
{
	int res = 0;
	int i = 0;
	int flag = 1;
	//1.检查空格
	while (s[i] == ' ')
		i++;
	//2.检查符号
	if (s[i] == '-')
		flag = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	//3.检查数字
	while (i < s.size() && isdigit(s[i]))
	{
		int r = s[i] - '0';
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7))
			return flag > 0 ? INT_MAX : INT_MIN;
		res = res * 10 + r;
		i++;
	}
	return flag > 0 ? res : -res;
}

int main()
{
	string input;
	getline(cin, input);
	cout << input << endl;
	int res = myAtoi(input);
	cout << res;
	return 0;
}