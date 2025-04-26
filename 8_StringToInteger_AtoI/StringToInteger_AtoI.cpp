// LeetCode : 8 - String to Integer (atoi) (https://leetcode.com/problems/string-to-integer-atoi/description/)

/*
Topics and Learnings: Recursion

Approach:
Used Recursion to solve this

Complexity Analysis:
TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int recur(string s, int i, int sign, long long res) {
		if (i >= s.size() || !isdigit(s[i])) return res * sign;

		res = res * 10 + s[i] - '0';

		if (res * sign <= INT_MIN) return INT_MIN;
		if (res * sign >= INT_MAX) return INT_MAX;

		return recur(s, i + 1, sign, res);
	}

	int myAtoi(string s) {

		size_t start = s.find_first_not_of(" ");
		if (start == string::npos) return 0;

		s = s.substr(start);
		if (s.empty()) return 0;

		int sign = 1, index = 0;
		if (s[0] == '-') sign = -1, index = 1;
		else if (s[0] == '+') index = 1;

		return recur(s, index, sign, 0);
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		Solution sol;
		int res = sol.myAtoi(s);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
3

42
-042
1337c0d3


Test Output : 1
42
-42
1337

*/
