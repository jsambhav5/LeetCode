// LeetCode : 29 - Divide Two Integers (https://leetcode.com/problems/divide-two-integers/)
// TUF+ : Divide two numbers without multiplication and division (https://takeuforward.org/plus/dsa/problems/divide-two-numbers-without-multiplication-and-division)

/*
Topics and Learnings: Bit-Manipulation

Approach:
Used Bitwise-Shift operation to solve this

Complexity Analysis:
TC: O((logN)^2)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == divisor) return 1;
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;
		if (divisor == 1) return dividend;

		int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

		long long n = abs((long long)dividend);
		long long d = abs((long long)divisor);
		int ans = 0;

		while (n >= d) {
			int p = 0;
			while (n >= (d << p)) p++;
			p--;
			n -= (d << p);
			ans += (1 << p);
		}

		return sign * ans;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int dividend, divisor;
		cin >> dividend >> divisor;

		Solution sol;
		int res = sol.divide(dividend, divisor);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
3

10 3
7 -3
7 2

Test Output : 1
3
-2
3

*/
