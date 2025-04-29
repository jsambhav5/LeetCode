// LeetCode : 1392 - Longest Happy Prefix (https://leetcode.com/problems/longest-happy-prefix/description/)
// TUF+ : Longest happy prefix (https://takeuforward.org/plus/dsa/strings--advanced-algo/advanced-problems-(less-asked)/longest-happy-prefix)

/*
Topics and Learnings: String

Approach:
APPROACH

Complexity Analysis:
TC: O()
SC: O()
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<int> computeLPS(string s) {
		int n = s.size();
		vector<int> LPS(n, 0);
		int i = 1, j = 0;

		while (i < n) {
			if (s[i] == s[j]) {
				LPS[i] = j + 1;
				i++, j++;
			}

			else {
				while (j > 0 && s[i] != s[j]) {
					j = LPS[j - 1];
				}

				if (s[i] == s[j]) {
					LPS[i] = j + 1;
					j++;
				}
				i += 1;
			}
		}

		return LPS;
	}
public:
	string lps(string s) {
		vector<int> lps = computeLPS(s);
		return s.substr(0, lps.back());
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		Solution sol;
		string res = sol.lps(s);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
3

ababab
aaaa
abc

Test Output : 1
OUTPUT

*/
