// LeetCode : 189 - Rotate Array (https://leetcode.com/problems/rotate-array/)

/*
Topics and Learnings:

Approach:
a) Reverse first n - k elements
b) Reverse remaining elements
c) Reverse the whole array

Complexiy Analysis:
TC: O(N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k = k % n;
		reverse(nums.begin(), nums.begin() + n - k);
		reverse(nums.begin() + n - k, nums.end());
		reverse(nums.begin(), nums.end());
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> arr;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			arr.push_back(input);
		}

		Solution sol;

		sol.rotate(arr, k);

		for (auto i : arr) {
			cout << i << " ";
		}

		cout << endl;
	}

	return 0;
}

/*
Test Input :
2

5 2
1 2 3 4 5

4 3
-1 0 3 6

Test Output : 1
4 5 1 2 3
0 3 6 -1

*/
