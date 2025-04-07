// LeetCode : 152 - Maximum Product Subarray (https://leetcode.com/problems/maximum-product-subarray/)
// TUF+ : Maximum Product Subarray in an Array (https://takeuforward.org/plus/dsa/arrays/faqs-hard/maximum-product-subarray-in-an-array)

/*
Topics and Learnings: Arrays, Kadane's Algorithm

Approach:
Ran loop from left to right and right to left to calculate the consecutive product and stored maximum product so far in a variable. Also, later solved it with a modified version of Kadane's Algorithm as well

Complexity Analysis:
TC: O(N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();

		int ans = INT_MIN;
		int pre = 1, suff = 1;

		for (int i = 0; i < n; i++) {
			if (pre == 0) pre = 1;
			if (suff == 0) suff = 1;

			pre *= nums[i];
			suff *= nums[n - i - 1];

			ans = max(ans, max(pre, suff));
		}

		return ans;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> arr;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			arr.push_back(input);
		}

		Solution sol;

		int ans = sol.maxProduct(arr);

		cout << ans << endl;
	}

	return 0;
}


/*
Test Input :
3
6
4 5 3 7 1 2
3
-5 0 -2
6
1 -2 3 4 -4 -3

Test Output :
840
0
144

*/
