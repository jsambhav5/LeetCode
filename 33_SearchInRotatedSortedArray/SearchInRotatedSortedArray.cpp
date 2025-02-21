// LeetCode : 33 - Search in Rotated Sorted Array (https://leetcode.com/problems/search-in-rotated-sorted-array/)
// TUF+ : Search in rotated sorted array-I (https://takeuforward.org/plus/dsa/binary-search/logic-building/search-in-rotated-sorted-array-i)

/*
Topics and Learnings: Binary Search

Approach:
if (low < mid) => left half is sorted
else right half is sorted

if number is present in sorted half => eleminate unsorted
else => eleminate sorted

TC: O(logN)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int low = 0, high = n - 1;

		while (low <= high) {
			int mid = (low + high) / 2;

			if (nums[mid] == target) return mid;

			if (nums[low] <= nums[mid]) {
				if (nums[low] <= target && nums[mid] >= target)
					high = mid - 1;
				else
					low = mid + 1;
			}

			else {
				if (nums[mid] <= target && nums[high] >= target)
					low = mid + 1;
				else
					high = mid - 1;
			}
		}

		return -1;
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

		int target;
		cin >> target;

		Solution sol;

		int ans = sol.search(arr, target);

		cout << ans << endl;
	}

	return 0;
}

/*
Test Input :
3

7
4 5 6 7 0 1 2
0

7
4 5 6 7 0 1 2
3

1
1
0

Test Output : 1
4
-1
-1

*/
