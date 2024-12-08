class Solution {
    const int mod = (int)1e9 + 7;
  
private:
    int func(vector<int>& num, int target) {
        int n = num.size();
        vector<int> prev(target + 1, 0);

        if (num[0] == 0) prev[0] = 2;  
        else prev[0] = 1;  

        if (num[0] != 0 && num[0] <= target)
            prev[num[0]] = 1;  

        for (int ind = 1; ind < n; ind++) {
            vector<int> cur(target + 1, 0);
        
            for (int tar = 0; tar <= target; tar++) {
                int notTaken = prev[tar];
                int taken = 0;
                    
                if (num[ind] <= tar)
                    taken = prev[tar - num[ind]];
                
                cur[tar] = (notTaken + taken) % mod;
            }

            prev = cur;
        }
        return prev[target];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = 0;

        for (int i = 0; i < nums.size(); i++)
            totSum += nums[i];

        if (totSum - target < 0 || (totSum - target) % 2 != 0)
            return 0;  

        return func(nums, (totSum - target) / 2);
    }
};
