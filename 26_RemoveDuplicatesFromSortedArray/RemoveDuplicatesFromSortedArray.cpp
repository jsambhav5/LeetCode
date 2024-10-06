#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int slow = 0, fast = 1;
		while (fast < nums.size()) {
			if (nums[slow] != nums[fast]) {
				slow++;
				nums[slow] = nums[fast];
			}
			fast++;
		}
		return slow + 1;
	}
};

int main(int argc, const char** argv) {
	Solution s;
	vector<int> nums = {1,1,2,2,2,3,3 };
	int k = s.removeDuplicates(nums);
	cout << k << endl;
	for(int i : nums)
		cout << i << " ";
	return 0;
}