// LeetCode : 410 - Split Array Largest Sum (https://leetcode.com/problems/split-array-largest-sum)
// TUF+ : Split array - largest sum (https://takeuforward.org/plus/dsa/binary-search/faqs/split-array---largest-sum)

/*
Topics and Learnings: Binary Search

Approach:
Used Binary search to solve this with range : [largest element, sum of all elements]

Complexity Analysis:
TC: O(N * (log(sum - max) + 1))
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool possible(vector<int>& nums, int k, int mid) {
		long long sum = 0;
		int parts = 1;
		for (int i : nums) {
			sum += i;
			if (sum > mid) {
				parts++;
				sum = i;
			}
		}
		return parts <= k;
	}

public:
	int splitArray(vector<int>& nums, int k) {
		int low = *max_element(nums.begin(), nums.end());
		int high = accumulate(nums.begin(), nums.end(), 0);
		int res = -1;

		while (low <= high) {
			int mid = (low + high) / 2;
			if (possible(nums, k, mid)) {
				res = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}
		return res;
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

		int k;
		cin >> k;

		Solution sol;

		int ans = sol.splitArray(arr, k);
		cout << ans << endl;
	}

	return 0;
}

/*
Test Input :
4

5
7 2 5 10 8
2

5
1 2 3 4 5
2

5
1 2 3 4 5
3

3
3 5 1
3

Test Output : 1
18
9
6
5

*/
