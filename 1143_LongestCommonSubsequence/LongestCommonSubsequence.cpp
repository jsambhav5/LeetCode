class Solution{
public:
    int longestCommonSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (str1[ind1 - 1] == str2[ind2 - 1])
                    cur[ind2] = 1 + prev[ind2 - 1]; 
                else
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
            }
            prev = cur; 
        }
        return prev[m]; 
    }
};
