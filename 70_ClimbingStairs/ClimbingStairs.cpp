// LeetCode : 70- Climbing Stairs (https://leetcode.com/problems/climbing-stairs)
// TUF+ : Climbing stairs (https://takeuforward.org/plus/dsa/dynamic-programming/1d-dp/climbing-stairs)

/*
Topics and Learnings: Dynamic Programming

Approach:
Used Dynamic Programming to solve this

Complexiy Analysis:
TC: O(N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int prev2 = 1;
		int prev = 1;

		for (int i = 2; i <= n; i++) {
			int cur_i = prev2 + prev;
			prev2 = prev;
			prev = cur_i;
		}
		return prev;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		Solution sol;
		int res = sol.climbStairs(n);

		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
2
2
3

Test Output : 1
2
3

*/
