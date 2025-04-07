// LeetCode : 283 - Move Zeroes (https://leetcode.com/problems/move-zeroes/description/)
// TUF+ : Move Zeros to End (https://takeuforward.org/plus/dsa/arrays/logic-building/move-zeros-to-end)

/*
Topics and Learnings:

Approach:
Used Two-Pointers to solve this

Complexity Analysis:
TC: O(N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		int nonZero = 0;
		for (int i = 0; i < n; i++)
			if (nums[i] != 0) {
				swap(nums[i], nums[nonZero]);
				nonZero++;
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

		sol.moveZeroes(arr);

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
0 2 43 0 5

5
1 2 0 4 0

3
0 2 3

Test Output : 1
2 43 5 0 0
1 2 4 0 0
2 3 0

*/
