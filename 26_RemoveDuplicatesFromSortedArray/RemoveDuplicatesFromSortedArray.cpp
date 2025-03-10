// LeetCode : 26 - Remove Duplicates from Sorted Array (https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)
// TUF+ : Remove duplicates from sorted array (https://takeuforward.org/plus/data-structures-and-algorithm/arrays/logic-building/remove-duplicates-from-sorted-array)

/*
Topics and Learnings:

Approach:
Used 2-Pointers to solve this

Complexiy Analysis:
TC: O(N)
SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int slow = 0, fast = 1;
		while (fast < nums.size()) {
			if (nums[slow] != nums[fast]) {
				slow++;
				nums[slow] = nums[fast];
			}
			fast++;
		}
		return slow + 1;
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

		int res = sol.removeDuplicates(arr);

		for (int i = 0; i < res; i++) {
			cout << arr[i] << " ";
		}

		cout << endl;
	}

	return 0;
}

/*
Test Input :
2

6
0 0 3 3 5 6

8
-2 2 4 4 4 4 5 5

Test Output : 1
OUTPUT

*/
