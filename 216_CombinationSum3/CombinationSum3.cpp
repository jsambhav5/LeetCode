// LeetCode : 40 - Combination Sum III (https://leetcode.com/problems/combination-sum-iii/)
// TUF+ : Combination Sum III (https://takeuforward.org/plus/dsa/problems/combination-sum-iii)

/*
Topics and Learnings: Recursion

Approach:
Used Recursion to solve this

Complexity Analysis:
TC: O(2^9 * K)
SC: O(K)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void func(int sum, int last, vector<int>& nums, int k, vector<vector<int>>& ans) {
		if (sum == 0 && nums.size() == k) {
			ans.push_back(nums);
			return;
		}

		if (sum <= 0 || nums.size() > k) return;

		for (int i = last; i <= 9; i++) {
			if (i <= sum) {
				nums.push_back(i);
				func(sum - i, i + 1, nums, k, ans);
				nums.pop_back();
			}
			else break;
		}
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ans;
		vector<int> nums;
		func(n, 1, nums, k, ans);
		return ans;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int k, n;
		cin >> k >> n;

		Solution sol;
		vector<vector<int>> res = sol.combinationSum3(k, n);

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

3 7
3 9
3 8

Test Output : 1
1 2 4

1 2 6
1 3 5
2 3 4

1 2 5
1 3 4

*/
