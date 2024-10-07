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