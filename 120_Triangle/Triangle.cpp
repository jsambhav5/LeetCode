class Solution {
private:
    int func(vector<vector<int> > &triangle, int n) {
        vector<int> front(n, 0); 
        vector<int> cur(n, 0);   
    
        for (int j = 0; j < n; j++)
            front[j] = triangle[n - 1][j];
    
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j + 1];
            
                cur[j] = min(down, diagonal);
            }
            
            front = cur;
        }
    
        return front[0];
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return func(triangle, n);
    }
};
