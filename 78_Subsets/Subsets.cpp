// LeetCode : 78 - Subsets (https://leetcode.com/problems/subsets)
// TUF+ : Power Set (https://takeuforward.org/plus/dsa/recursion/implementation-problems/power-set)

/*
Topics and Learnings: Recursion

Approach:
Used Recursion to solve this

Complexity Analysis:
TC: O(2^N)
SC: O(N * 2^N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void func(int ind, int n, vector<int>& nums, vector<int>& arr, vector<vector<int>>& ans) {
		if (ind == n) {
			ans.push_back(arr);
			return;
		}

		func(ind + 1, n, nums, arr, ans);
		arr.push_back(nums[ind]);

		func(ind + 1, n, nums, arr, ans);
		arr.pop_back();
	}

public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> arr;
		func(0, nums.size(), nums, arr, ans);
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
		vector<vector<int>> res = sol.subsets(arr);

		for (auto i : res) {
			cout << "[";
			for (auto j : i) {
				cout << j << " , ";
			}
			cout << "]" << endl;
		}
		cout << endl;
	}

	return 0;
}

/*
Test Input :
2

3
1 2 3

1
0

Test Output : 1
[]
[3 , ]
[2 , ]
[2 , 3 , ]
[1 , ]
[1 , 3 , ]
[1 , 2 , ]
[1 , 2 , 3 , ]

[]
[0 , ]


*/
