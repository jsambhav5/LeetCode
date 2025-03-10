// LeetCode : 75 - Sort Colors (https://leetcode.com/problems/sort-colors/description/)
// TUF+ : Sort an array of 0's 1's and 2's (https://takeuforward.org/plus/dsa/arrays/faqs-medium/sort-an-array-of-0's-1's-and-2's)

/*
Topics and Learnings:

Approach:
Used 3-Pointers to solve this

Complexiy Analysis:
TC: O(N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int low = 0, mid = 0, high = nums.size() - 1;
		while (mid <= high) {
			if (nums[mid] == 0) {
				swap(nums[low], nums[mid]);
				low++;
				mid++;
			}
			else if (nums[mid] == 1) {
				mid++;
			}
			else {
				swap(nums[high], nums[mid]);
				high--;
			}
		}
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

		sol.sortColors(arr);

		for (auto i : arr) {
			cout << i << " ";
		}

		cout << endl;
	}

	return 0;
}

/*
Test Input :
3

5
1 0 2 1 0

5
0 0 1 1 1

5
1 1 2 2 1

Test Output : 1
0 0 1 1 2
0 0 1 1 1
1 1 1 2 2

*/
