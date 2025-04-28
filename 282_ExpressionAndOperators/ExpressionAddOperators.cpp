// LeetCode : 282 - Expression Add Operators (https://leetcode.com/problems/expression-add-operators/description/)

/*
Topics and Learnings: Recursion

Approach:
Used Recursion to solve this

Complexity Analysis:
TC: O(4^N)
SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void solve(int ind, string num, int target, string str, vector<string>& ans, long long prev, long long result) {
		if (ind == num.size()) {
			if (result == target) {
				ans.push_back(str);
			}
			return;
		}
		for (int i = ind; i < num.size(); i++) {
			if (i > ind && num[ind] == '0') break;
			string n = num.substr(ind, i - ind + 1);
			long long number = stoll(n);
			if (ind == 0) {
				solve(i + 1, num, target, n, ans, number, number);
			}
			else {
				solve(i + 1, num, target, str + "+" + n, ans, number, result + number);
				solve(i + 1, num, target, str + "-" + n, ans, -number, result - number);
				solve(i + 1, num, target, str + "*" + n, ans, prev * number, result - prev + (prev * number));
			}
		}
	}
	vector<string> addOperators(string num, int target) {
		vector<string> ans;
		solve(0, num, target, "", ans, 0, 0);
		return ans;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int n;
		cin >> n;

		Solution sol;
		vector<string> res = sol.addOperators(s, n);

		for (auto i: res) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}

/*
Test Input :
3

123
6

232
8

3456237490
9191

Test Output : 1
1+2+3 1*2*3
2+3*2 2*3+2


*/
