// LeetCode : 22 - Generate Parentheses (https://leetcode.com/problems/generate-parentheses)
// TUF+ : Generate Parentheses (https://takeuforward.org/plus/dsa/recursion/implementation-problems/generate-paranthesis)

/*
Topics and Learnings: Recursion

Approach:
Used Recursion to solve this

Complexity Analysis:
TC: O(4^n / sqrt(n))
SC: O(4^n / sqrt(n))
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void func(int open, int close, int n, string s, vector<string>& ans) {
		if (open == close && (open + close) == 2 * n) {
			ans.push_back(s);
			return;
		}

		if (open < n) {
			func(open + 1, close, n, s + '(', ans);
		}

		if (close < open) {
			func(open, close + 1, n, s + ')', ans);
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		func(0, 0, n, "", ans);
		return ans;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		Solution sol;
		vector<string> res = sol.generateParenthesis(n);

		for (auto i : res) {
			cout << i << " , ";
		}
		cout << endl;
	}

	return 0;
}

/*
Test Input :
3
3
2
1

Test Output : 1
((())) , (()()) , (())() , ()(()) , ()()() ,
(()) , ()() ,
() ,

*/
