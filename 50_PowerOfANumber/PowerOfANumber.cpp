// LeetCode : 50 - Pow(x, n) (https://leetcode.com/problems/powx-n/)
// TUF+ : Pow(x,n) (https://takeuforward.org/plus/dsa/recursion/implementation-problems/pow(x,n))

/*
Topics and Learnings: Recursion

Approach:
Used Recursion to solve this

Complexity Analysis:
TC: O(logN)
SC: O(logN)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	double power(double x, long n) {
		if (n == 0) return 1.0;
		if (n == 1) return x;
		if (n % 2 == 0) return power(x * x, n / 2);
		return x * power(x, n - 1);
	}

public:
	double myPow(double x, int n) {
		int num = n;
		if (num < 0) return (1.0 / power(x, -1 * (double)num));
		return power(x, num);
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		double x;
		int n;
		cin >> x >> n;

		Solution sol;
		double res = sol.myPow(x, n);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
3
2.00000 10
2.10000 3
2.00000 -2

Test Output : 1
1024
9.261
0.25

*/
