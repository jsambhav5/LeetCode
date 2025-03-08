// LeetCode : 153 - Find Minimum in Rotated Sorted Array (https://leetcode.com/problems/find-minimum-in-rotated-sorted-array)
// TUF+ : Find minimum in Rotated Sorted Array (https://takeuforward.org/plus/dsa/binary-search/logic-building/find-minimum-in-rotated-sorted-array)

/*
Topics and Learnings: Binary Search

Approach:
if (low < mid) => left half is sorted
else right half is sorted

if left half is sorted => ans = min(ans, nums[low])
else => ans = min(ans, nums[mid])

Complexiy Analysis:
Complexiy Analysis:
TC: O(logN)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		int low = 0, high = n - 1;
		int ans = INT_MAX;

		while (low <= high) {
			int mid = (low + high) / 2;

			if (nums[low] <= nums[mid]) {
				ans = min(ans, nums[low]);
				low = mid + 1;
			}
			else {
				ans = min(ans, nums[mid]);
				high = mid - 1;
			}
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

		int ans = sol.findMin(arr);

		cout << ans << endl;
	}

	return 0;
}

/*
Test Input :
3

10
7 8 1 2 3 3 3 4 5 6

8
4 5 6 7 0 1 2 3

10
7 8 8 2 3 3 3 4 5 6

Test Output : 1
1
0
2

*/
