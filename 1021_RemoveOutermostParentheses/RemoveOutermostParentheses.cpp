// LeetCode : 1021 - Remove Outermost Parentheses (https://leetcode.com/problems/remove-outermost-parentheses)

/*
Topics and Learnings: String, Linear Traversal

Approach:
Used Linear Traversal to solve this

Complexiy Analysis:
TC: O(N)
SC: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

// Using Stack - Not very optimal
/*
class Solution {
public:
	string removeOuterParentheses(string& s) {
		if (s == "") return s;
		string res = "";
		stack<char> st;
		int start = 0;
		for (int i = 0; i < s.length(); i++) {
			if (!st.empty()) {
				if (st.top() == '(' && s[i] == ')')
					st.pop();
				else
					st.push(s[i]);
			}
			if (st.empty() && start != i && s[start] == '(' && s[start + 1] == '(' && s[i - 1] == ')' && s[i] == ')') {
				st.push('(');
				res += s.substr(start + 1, i - start - 1);
				start = ++i;
			}
		}
		return res;
	}
};
*/

// More Optimal Approach
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

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		Solution sol;
		string res = sol.removeOuterParentheses(s);
		cout << "\"" << res << "\"" << endl;
	}

	return 0;
}

/*
Test Input :
3
(()())(())
(()())(())(()(()))
()()

Test Output : 1
"()()()"
"()()()()(())"
""

*/
