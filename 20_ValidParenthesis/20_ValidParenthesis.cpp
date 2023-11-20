#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> check;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				check.push(s[i]);
			else if (s[i] == ')') {
				if (!check.empty() && check.top() == '(')
					check.pop();
				else return false;
			}
			else if (s[i] == '}') {
				if (!check.empty() && check.top() == '{')
					check.pop();
				else return false;
			}
			else if (s[i] == ']') {
				if (!check.empty() && check.top() == '[')
					check.pop();
				else return false;
			}
		}
		if (check.empty())
			return true;
		return false;
	}
}S;

int main(int argc, const char** argv) {
	string s = "[({}(({[[]]{[[]}})))]";
	cout << S.isValid(s);
	return 0;
}