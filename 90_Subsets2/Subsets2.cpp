// LeetCode : 90 - Subsets II (https://leetcode.com/problems/subsets-ii/description/)
// TUF+ : Subsets II (https://takeuforward.org/plus/dsa/problems/subsets-ii)

/*
Topics and Learnings: Recursion

Approach:
Used Recursion to solve this

Complexity Analysis:
TC: (2^N * N)
SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void func(int ind, vector<int>& arr, vector<int>& nums, vector<vector<int>>& ans) {
		if (ind == nums.size()) {
			ans.push_back(arr);
			return;
		}

		arr.push_back(nums[ind]);
		func(ind + 1, arr, nums, ans);
		arr.pop_back();

		for (int j = ind + 1; j < nums.size(); j++) {
			if (nums[j] != nums[ind]) {
				func(j, arr, nums, ans);
				return;
			}
		}

		func(nums.size(), arr, nums, ans);
	}

public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> arr;
		sort(nums.begin(), nums.end());
		func(0, arr, nums, ans);
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
		vector<vector<int>> res = sol.subsetsWithDup(arr);

		for (auto i : res) {
			cout << "[";
			for (auto j : i) {
				cout << j << " ";
			}
			cout << "]" << endl;
		}
		cout << endl;
	}

	return 0;
}

/*
Test Input :
3

3
1 2 2

2
1 2

3
1 3 3

Test Output : 1
[1 2 2 ]
[1 2 ]
[1 ]
[2 2 ]
[2 ]
[]

[1 2 ]
[1 ]
[2 ]
[]

[1 3 3 ]
[1 3 ]
[1 ]
[3 3 ]
[3 ]
[]

*/
