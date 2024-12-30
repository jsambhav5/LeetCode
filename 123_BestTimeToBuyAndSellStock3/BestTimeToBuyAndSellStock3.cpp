class Solution {
private:
    int func(vector<int>& arr, int n) {
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 0)
                        cur[buy][cap] = max(0 + ahead[0][cap], -arr[ind] + ahead[1][cap]);
                    
                    if (buy == 1)
                        cur[buy][cap] = max(0 + ahead[1][cap], arr[ind] + ahead[0][cap - 1]);
                }
            }
            ahead = cur;
        }

        return ahead[0][2];
    }
public:
    int maxProfit(vector<int> &arr){
        return func(arr, arr.size());
    }
};
