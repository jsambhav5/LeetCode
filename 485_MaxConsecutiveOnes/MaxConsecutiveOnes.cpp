// LeetCode - 485 : Max Consecutive Ones (https://leetcode.com/problems/max-consecutive-ones/description/)
//TUF+ : Maximum Consecutive Ones (https://takeuforward.org/plus/dsa/arrays/fundamentals/maximum-consecutive-ones)

/*
Approach:
Used Linear Traversal to solve this

Complexiy Analysis:
TC: O(N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int count = 0, maxOnes = 0;
		for (int i : nums) {
			if (i == 1)
				count++;
			else if (i == 0) {
				maxOnes = max(maxOnes, count);
				count = 0;
			}
		}
		maxOnes = max(maxOnes, count);
		return maxOnes;
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

		int res = sol.findMaxConsecutiveOnes(arr);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
2

8
1 1 0 0 1 1 1 0

6
1 0 1 1 0 1

Test Output : 1
3
2
*/
