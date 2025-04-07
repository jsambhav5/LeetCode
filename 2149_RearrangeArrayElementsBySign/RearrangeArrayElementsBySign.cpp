// LeetCode : 2149 - Rearrange Array Elements by Sign (https://leetcode.com/problems/rearrange-array-elements-by-sign/description/)
// TUF+ : Rearrange array elements by sign (https://takeuforward.org/plus/dsa/arrays/faqs-medium/rearrange-array-elements-by-sign)

/*
Topics and Learnings:

Approach:
Used Linear Traversal to solve this

Complexity Analysis:
TC: O(N)
SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n, 0);

		int pos = 0, neg = 1;
		for (int i = 0; i < n; i++) {
			if (nums[i] > 0) {
				res[pos] = nums[i];
				pos += 2;
			}
			else {
				res[neg] = nums[i];
				neg += 2;
			}
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

		Solution sol;

		vector<int> res = sol.rearrangeArray(arr);

		for (auto i : res) {
			cout << i << " ";
		}

		cout << endl;
	}

	return 0;
}

/*
Test Input :
3

6
2 4 5 -1 -3 -4

6
1 -1 -3 -4 2 3

6
-4 4 -4 4 -4 4

Test Output : 1
2 -1 4 -3 5 -4
1 -1 2 -3 3 -4
4 -4 4 -4 4 -4

*/
