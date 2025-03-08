// LeetCode : 18 - 4Sum (https://leetcode.com/problems/4sum/description/)
// TUF+ : 4 Sum (https://takeuforward.org/plus/dsa/arrays/faqs-medium/4-sum)

/*
Approach:
1. Sort the array
2. Used 4 pointers with triple nested loop to find the required quadruplets

Complexiy Analysis:
TC: O(N^3)
SC: O(N^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;

		int n = nums.size();

		sort(nums.begin(), nums.end());

		for (int i = 0; i < n; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			for (int j = i + 1; j < n; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;

				int k = j + 1;
				int l = n - 1;

				while (k < l) {
					long long sum = nums[i] + nums[j];
					sum += nums[k];
					sum += nums[l];

					if (sum == target) {
						vector<int> temp = { nums[i], nums[j], nums[k], nums[l] };
						ans.push_back(temp);

						k++;
						l--;
						while (k < l && nums[k] == nums[k - 1]) k++;
						while (k < l && nums[l] == nums[l + 1]) l--;
					}
					else if (sum < target) k++;
					else l--;
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
		int n, target;
		cin >> target;
		cin >> n;

		vector<int> arr;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			arr.push_back(input);
		}

		Solution sol;

		vector<vector<int>> ans = sol.fourSum(arr, target);

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

7 6
1 -2 3 5 7 9

9 6
7 -7 1 2 14 3

5 5
1 1 3 4 -3

Test Output : 1
[ [-2 1 3 5 ] ]
[ ]
[ [-3 1 3 4 ] ]

*/
