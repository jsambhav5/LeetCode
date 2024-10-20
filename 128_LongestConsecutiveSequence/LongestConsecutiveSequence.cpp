
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

int main() {
	vector<int> a = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };

	Solution solution;

	int ans = solution.longestConsecutive(a);
	cout << ans;
	return 0;
}
