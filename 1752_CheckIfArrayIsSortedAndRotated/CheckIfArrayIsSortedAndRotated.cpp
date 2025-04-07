// LeetCode : 1752 - NAME (https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)
// TUF : Check if the array is sorted (https://takeuforward.org/data-structure/check-if-an-array-is-sorted/)

/*
Topics and Learnings:

Approach:
If array is roated, a[i] > a[i + 1] can happen once otherwise it cannot happen

Complexity Analysis:
TC: O(N)
SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool check(vector<int>& nums) {
		int count = 0;
		int n = nums.size();

		for (int i = 1; i < n; i++) {
			if (nums[i] < nums[i - 1])
				count++;
			if (count >= 2)
				return false;
		}
		if (nums[0] < nums[n - 1])
			count++;
		if (count < 2)
			return true;
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

		Solution sol;

		bool res = sol.check(arr);

		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
3

5
3 4 5 1 2

4
2 1 3 4

3
1 2 3

Test Output : 1
1
0
1
*/
