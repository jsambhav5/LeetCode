// LeetCode : 34 - Find First and Last Position of Element in Sorted Array (https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
// TUF+ : First and last occurrence (https://takeuforward.org/plus/dsa/binary-search/logic-building/first-and-last-occurrence)

/*
Topics and Learnings: Binary Search

Approach:
Used Binary Search to solve this
First Occurrence = Lower Bound
Last Occurrence = Upper Bound - 1

Complexiy Analysis:
TC: O(logN)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

	int lowerBound(vector<int>& nums, int x) {
		int ans = nums.size();
		int low = 0, high = ans - 1;

		while (low <= high) {
			int mid = (low + high) / 2;

			if (nums[mid] >= x) {
				ans = mid;
				high = mid - 1;
			}

			else low = mid + 1;
		}

		return ans;
	}

	int upperBound(vector<int>& nums, int x) {
		int ans = nums.size();
		int low = 0, high = ans - 1;

		while (low <= high) {
			int mid = (low + high) / 2;

			if (nums[mid] > x) {
				ans = mid;
				high = mid - 1;
			}

			else low = mid + 1;
		}

		return ans;
	}

public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int n = nums.size();
		int lb = lowerBound(nums, target);
		if (lb == n || nums[lb] != target) return { -1, -1 };
		int ub = upperBound(nums, target);
		return { lb, ub - 1 };
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

		vector<int> ans = sol.searchRange(arr, target);

		for (auto i : ans) {
			cout << i << " ";
		}

		cout << endl;
	}

	return 0;
}

/*
Test Input :
4

6
5 7 7 8 8 10
8

6
5 7 7 8 8 10
6

0
0

6
5 7 7 8 8 10
5

Test Output : 1
3 4
-1 -1
-̄1 -1
0 0

*/
