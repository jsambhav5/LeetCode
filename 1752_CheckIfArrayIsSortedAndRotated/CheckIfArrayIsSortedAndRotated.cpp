#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool check(vector<int>& nums) {
		int count = 0;
		int n = nums.size();

		for (int i = 1; i < n; i++) {
			if (nums[i] < nums[i - 1])
				count++;
			if (count >= 2)
				return false;
		}
		if (nums[0] < nums[n - 1])
			count++;
		if (count < 2)
			return true;
		return false;
	}
};