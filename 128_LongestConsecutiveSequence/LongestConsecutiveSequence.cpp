// LeetCode : 128 - Longest Consecutive Sequence (https://leetcode.com/problems/longest-consecutive-sequence/description/)
// TUF+ : Longest Consecutive Sequence in an Array (https://takeuforward.org/plus/dsa/hashing/faqs/longest-consecutive-sequence-in-an-array)

/*
Used hashing to solve this

Complexity Analysis:
TC: O(N ^ 2)
SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
	int longestConsecutive(vector<int>& nums) {
		int n = nums.size();

		if (n == 0) return 0;

		unordered_set<int> mem;
		int longest = 1;

		for (int i = 0; i < n; i++)
			mem.insert(nums[i]);

		for (int i : mem) {
			if (mem.find(i - 1) == mem.end()) {
				int count = 1;
				int x = i;

				while (mem.find(x + 1) != mem.end()) {
					x++;
					count++;
				}
				longest = max(longest, count);
			}
		}

		return longest;
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

		int res = sol.longestConsecutive(arr);

		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
3

6
100 4 200 1 3 2

10
0 3 7 2 5 8 4 6 0 1

7
1 9 3 10 4 20 2

Test Output : 1
4
9
4

*/
