// LeetCode : 40 - Combination Sum II (https://leetcode.com/problems/combination-sum-ii/)
// TUF+ : Combination Sum II (https://takeuforward.org/plus/dsa/problems/combination-sum-ii)

/*
Topics and Learnings: Recursion

Approach:
Used Recursion to solve this

Complexity Analysis:
TC: O(N * 2^N)
SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void func(int ind, int sum, vector<int>& nums,
		vector<int>& candidates, vector<vector<int>>& ans) {
		if (sum == 0) {
			ans.push_back(nums);
			return;
		}

		if (sum < 0 || ind == candidates.size()) return;

		nums.push_back(candidates[ind]);

		func(ind + 1, sum - candidates[ind], nums, candidates, ans);
		nums.pop_back();

		for (int i = ind + 1; i < candidates.size(); i++) {
			if (candidates[i] != candidates[ind]) {
				func(i, sum, nums, candidates, ans);
				break;
			}
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> nums;
		sort(candidates.begin(), candidates.end());
		func(0, target, nums, candidates, ans);
		return ans;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n, target;
		cin >> n >> target;

		vector<int> candidates;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			candidates.push_back(input);
		}

		Solution sol;
		vector<vector<int>> res = sol.combinationSum2(candidates, target);

		for (auto i : res) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}

/*
Test Input :
3

7 8
10 1 2 7 6 1 5

5 5
2 5 2 1 2

7 8
2 1 2 7 6 1 5

Test Output : 1
1 1 6
1 2 5
1 7
2 6

1 2 2
5

1 1 6
1 2 5
1 7
2 6

*/
