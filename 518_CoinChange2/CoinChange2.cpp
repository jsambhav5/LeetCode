class Solution{
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<double> prev(amount + 1, 0);  

        for (int i = 0; i <= amount; i++)
            if (i % coins[0] == 0) prev[i] = 1;  

        for (int ind = 1; ind < N; ind++) {
            vector<double> cur(amount + 1, 0);  
            for (int target = 0; target <= amount; target++) {
                double notTaken = prev[target];  
                double taken = 0;
                
                if (coins[ind] <= target)
                    taken = cur[target - coins[ind]];

                cur[target] = (double) notTaken + taken;  
            }
            prev = cur;  
        }
        return prev[amount];  
    }
};
