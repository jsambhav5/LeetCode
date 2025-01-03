class Solution{
public:
    int minDistance(string start, string target) {
        int n = start.size();
        int m = target.size();
        vector<int> prev(m + 1, 0);
        vector<int> cur(m + 1, 0);

        for (int j = 0; j <= m; j++)
            prev[j] = j;

        for (int i = 1; i <= n; i++) {
            cur[0] = i; 
            for (int j = 1; j <= m; j++) {
                if (start[i - 1] == target[j - 1])
                    cur[j] = prev[j - 1];
                else 
                  cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
            }
            prev = cur; 
        }
        if(n < 1)
            return prev[m];
        return cur[m];
    }
};
