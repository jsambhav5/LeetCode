// LeetCode : 81 - Search in Rotated Sorted Array II (https://leetcode.com/problems/search-in-rotated-sorted-array-ii)
// TUF+ : Search in rotated sorted array-II (https://takeuforward.org/plus/dsa/binary-search/logic-building/search-in-rotated-sorted-array-2)

/*
Topics and Learnings: Binary Search

Approach:
Similar to "search in rotated sorted array "with just 1 extra edge case
if nums[low] == nums[mid] == nums[high] => low++, high++;

Complexiy Analysis:
TC: O(logN)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int n = nums.size();
		int low = 0, high = n - 1;

		while (low <= high) {
			int mid = (low + high) / 2;

			if (nums[mid] == target) return true;

			if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
				low++;
				high--;
				continue;
			}

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

		return false;
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

		cout << (bool)ans << endl;
	}

	return 0;
}

/*
Test Input :
3

10
7 8 1 2 3 3 3 4 5 6
3

10
7 8 1 2 3 3 3 4 5 6
10

10
7 8 1 2 3 3 3 4 5 6
7

Test Output : 1
True
False
True

*/
