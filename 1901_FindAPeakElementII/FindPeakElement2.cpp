class Solution {
public:
	vector<int> findPeakGrid(vector<vector<int>>& mat) {
		int n = mat.size();
		int m = mat[0].size();

		int low = 0, high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;

			int col = max_element(mat[mid].begin(), mat[mid].end())
				- mat[mid].begin();
			int ele = mat[mid][col];

			int up = mid > 0 ? mat[mid - 1][col] : INT_MIN;
			int down = mid < n - 1 ? mat[mid + 1][col] : INT_MIN;

			if (ele > up && ele > down) return { mid, col };

			if (ele > up) low = mid + 1;
			else high = mid - 1;
		}

		return { -1, -1 };
	}
};