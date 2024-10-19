class Solution {
public:
	vector<int> majorityElementTwo(vector<int>& nums) {
		int n = nums.size();

		int num1 = INT_MIN;
		int num2 = INT_MIN;

		int count1 = 0;
		int count2 = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (count1 == 0 && nums[i] != num2) {
				count1 = 1;
				num1 = nums[i];
			}

			else if (count2 == 0 && nums[i] != num1) {
				count2 = 1;
				num2 = nums[i];
			}

			else if (nums[i] == num1)
				count1++;

			else if (nums[i] == num2)
				count2++;

			else {
				count1--;
				count2--;
			}
		}

		count1 = 0;
		count2 = 0;

		for (int i = 0; i < n; i++) {
			if (nums[i] == num1) count1++;
			if (nums[i] == num2) count2++;
		}

		int min = (n / 3) + 1;

		vector<int> ans;

		if (count1 >= min) ans.push_back(num1);
		if (count2 >= min) ans.push_back(num2);

		return ans;
	}
};