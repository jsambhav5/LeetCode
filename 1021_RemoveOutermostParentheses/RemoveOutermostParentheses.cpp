#include<bits/stdc++.h>
using namespace std;

// Using Stack
// class Solution {
// public:
// 	string removeOuterParentheses(string& s) {
// 		if (s == "") return s;
// 		string res = "";
// 		stack<char> st;
// 		int start = 0;
// 		for (int i = 0; i < s.length(); i++) {
// 			if (!st.empty()) {
// 				if (st.top() == '(' && s[i] == ')')
// 					st.pop();
// 				else
// 					st.push(s[i]);
// 			}
// 			if (st.empty() && start != i && s[start] == '(' && s[start + 1] == '(' && s[i - 1] == ')' && s[i] == ')') {
// 				st.push('(');
// 				res += s.substr(start + 1, i - start - 1);
// 				start = ++i;
// 			}
// 		}
// 		return res;
// 	}
// };

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
