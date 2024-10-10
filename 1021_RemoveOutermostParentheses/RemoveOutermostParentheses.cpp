#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string removeOuterParentheses(string s) {
		if (s == "") return s;
		string res = "";
		int start = 0, balance = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				if (balance != 0) res += "(";
				balance++;
			}
			else {
				balance--;
				if (balance > 0)
					res += ")";
			}
		}
		return res;
	}
};

int main(int argc, char const* argv[])
{
	Solution  s;
	string str = "(()())(())(()(()))";
	cout << s.removeOuterParentheses(str);
	return 0;
}
