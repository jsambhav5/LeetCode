// LeetCode : 39 - Combination Sum (https://leetcode.com/problems/combination-sum/description/)
// TUF+ : Combination Sum (https://takeuforward.org/plus/dsa/problems/combination-sum)

/*
Topics and Learnings: Recursion

Approach:
Used Recursion to solve this

Complexity Analysis:
TC: O(K * 2^N)
SC: O(k * N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void func(vector<int>& v, int i, int sum, vector<int>& v2, vector<vector<int>>& ans) {
		if (sum == 0) {
			ans.push_back(v2);
			return;
		}

		if (sum < 0) return;

		if (i < 0) return;

		func(v, i - 1, sum, v2, ans);
		v2.push_back(v[i]);

		func(v, i, sum - v[i], v2, ans);
		v2.pop_back();
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> v;
		func(candidates, candidates.size() - 1, target, v, ans);
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
		vector<vector<int>> res = sol.combinationSum(candidates, target);

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

4 7
2 3 5 4

1 1
2

1 1
1

Test Output : 1
3 2 2
5 2
4 3


1


*/
