// LeetCode : 214 - Shortest Palindrome (https://leetcode.com/problems/shortest-palindrome/description/)
// TUF+ : Shortest Palindrome (https://takeuforward.org/plus/dsa/problems/shortest-palindrome)

/*
Topics and Learnings: String, KMP Algorithm

Approach:
Used Knuth–Morris–Pratt algorithm to solve this

Complexity Analysis:
TC: O(N)
SC: O(N)
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
	string shortestPalindrome(string s) {
		string revs = s;
		reverse(revs.begin(), revs.end());
		string str = s + '$' + revs;
		vector<int> lps = computeLPS(str);
		int ans = s.size() - lps.back();
		string to_add = revs.substr(0, ans);
		return to_add + s;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		Solution sol;
		string res = sol.shortestPalindrome(s);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
3

aacecaaa
race
abcd

Test Output : 1
aaacecaaa
ecarace
dcbabcd

*/
