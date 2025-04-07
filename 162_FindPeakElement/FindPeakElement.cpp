// LeetCode : 162 - Find Peak Element (https://leetcode.com/problems/find-peak-element/description/)
// TUF+ : Find peak element (https://takeuforward.org/plus/dsa/binary-search/faqs/find-peak-element)

/*
Topics and Learnings: Binary Search

Approach:
Used Binary Search to solve this

Complexity Analysis:
Complexity Analysis:
TC: O(logN)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();

		if (n == 1) return 0;
		if (nums[0] > nums[1]) return 0;
		if (nums[n - 1] > nums[n - 2]) return n - 1;

		for (int i = 1; i < n - 1; i++)
			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
				return i;

		return n - 1;
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

		int res = sol.findPeakElement(arr);

		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
3

10
1 2 3 4 5 6 7 8 5 1

7
1 2 1 3 4 6 4

5
-2 -1 3 4 5

Test Output : 1
7
1
4

*/
