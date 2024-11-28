class Solution {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    
    bool isValid(int &i, int &j, int &n, int &m) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }
    
    void dfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>& image, int newColor, int iniColor) {
        ans[row][col] = newColor; 
        int n = image.size();
        int m = image[0].size(); 
        
        for(int i=0; i < 4; i++) {
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i]; 
            
            if(isValid(nrow, ncol, n, m) &&  image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
                dfs(nrow, ncol, ans, image, newColor, iniColor); 
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc]; 
        vector<vector<int>> ans = image; 
        dfs(sr, sc, ans, image, newColor, iniColor); 
        return ans; 
    }
};
