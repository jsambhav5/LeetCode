// LeetCode : 139 - Word Break (https://leetcode.com/problems/word-break/description/)

/*
Topics and Learnings: Recursion

Approach:
Used Recursion to solve this

Complexity Analysis:
TC: O(N^2)
SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	unordered_map<string, bool>m;
	vector<int>dp;
	bool solve(int i, string& str) {
		if (i >= str.size()) {
			return true;
		}

		if (dp[i] != -1) {
			return dp[i];
		}

		bool res = false;

		for (int j = i; j < str.size(); j++) {
			string temp = str.substr(i, j - i + 1);
			if (m.find(temp) != m.end()) {
				if (solve(j + 1, str)) {
					return dp[i] = true;
				}
			}
		}
		return dp[i] = false;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		for (auto w : wordDict) {
			m[w] = true;
		}
		int n = s.size();
		dp.resize(n + 1, -1);
		return solve(0, s);
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		vector<string> wordDict;
		for(int i = 0; i < n; i++) {
			string input;
			cin >> input;
			wordDict.push_back(input);
		}

		Solution sol;
		bool res = sol.wordBreak(s, wordDict);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
3

2
leetcode
leet code

2
applepenapple
apple pen

5
catsandog
cats dog sand and cat

Test Output : 1
1
1
0

*/
