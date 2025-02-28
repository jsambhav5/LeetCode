// LeetCode : 540 - Single Element in a Sorted Array (https://leetcode.com/problems/single-element-in-a-sorted-array)
// TUF+ : Single element in sorted array (https://takeuforward.org/plus/dsa/binary-search/logic-building/single-element-in-sorted-array)

/*
Topics and Learnings: Binary Search

Approach:
Used Binary Search to Solve this

Complexiy Analysis:
TC: O(logN)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return nums[0];
		if (nums[0] != nums[1]) return nums[0];
		if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

		int low = 1, high = n - 2;
		int mid;

		while (low <= high) {
			mid = (low + high) / 2;

			if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
				return nums[mid];

			if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 != 0 && nums[mid] == nums[mid - 1]))
				low = mid + 1;
			else high = mid - 1;
		}

		return mid;
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

		int res = sol.singleNonDuplicate(arr);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
2

9
1 1 2 3 3 4 4 8 8

7
3 3 7 7 10 11 11

Test Output : 1
2
10

*/
