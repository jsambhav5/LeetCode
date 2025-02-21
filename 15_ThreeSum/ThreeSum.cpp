// LeetCode : 15 - 3Sum (https://leetcode.com/problems/3sum/description/)
// TUF+ : 3 Sum (https://takeuforward.org/plus/dsa/arrays/faqs-medium/3-sum)

/*
Approach:
1. Sort the array
2. Use 3 pointers to find the required pair

TC: O(N^2)
SC: O(N^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int n = nums.size();

		sort(nums.begin(), nums.end());

		for (int i = 0; i < n; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int j = i + 1;
			int k = n - 1;

			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];

				if (sum < 0)
					j++;
				else if (sum > 0)
					k--;
				else {
					vector<int> temp = { nums[i], nums[j], nums[k] };
					ans.push_back(temp);
					j++;
					k--;
					while (j < k && nums[j] == nums[j - 1]) j++;
					while (j < k && nums[k] == nums[k + 1]) k--;
				}
			}
		}
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

		vector<vector<int>> ans = sol.threeSum(arr);

		cout << "[ ";
		for (auto vec : ans) {
			cout << "[";
			for (auto ele : vec)
				cout << ele << " ";
			cout << "] ";
		}
		cout << "]" << endl;
	}

	return 0;
}

/*
Test Input :
3

6
2 -2 0 3 -3 5

5
2 -1 -1 3 -1

4
8 -6 5 4

Test Output : 1
[ [-3 -2 5 ] [-3 0 3 ] [-2 0 2 ] ]
[ [-1 -1 2 ] ]
[ ]

*/
