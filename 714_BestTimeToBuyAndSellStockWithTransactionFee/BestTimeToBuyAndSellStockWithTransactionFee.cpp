class Solution {
private:
    int func(vector<int>& arr, int n, int fee) {
        vector<int> ahead(2, 0);
        vector<int> cur(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0)
                    cur[buy] = max(0 + ahead[0], -arr[ind] + ahead[1]);
                
                if (buy == 1)
                    cur[buy] = max(0 + ahead[1], arr[ind]-fee + ahead[0]);
            }
            ahead = cur;
        }

        return cur[0];
    }
    
public:
    int maxProfit(vector<int> &arr, int fee){
        return func(arr, arr.size(), fee);
    }
};
