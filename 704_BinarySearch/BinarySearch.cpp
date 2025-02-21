// LeetCode : 704 - Binary Search (https://leetcode.com/problems/binary-search/)
// TUF+ : Binary Search (https://takeuforward.org/plus/dsa/binary-search/fundamentals/search-x-in-sorted-array)

/*
Topics and Learnings: Binary Search

Approach:
Used Binary Search to solve this

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

			if (nums[mid] == target)
				return mid;

			else if (nums[mid] > target)
				high = mid - 1;

			else
				low = mid + 1;
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
2
6
-1 0 3 5 9 12
9
6
-1 0 3 5 9 12
2

Test Output : 1
4
-1

*/
