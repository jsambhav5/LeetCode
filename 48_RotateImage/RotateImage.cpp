class Solution {
private:
	void transpose(vector<vector<int>>& arr) {
		int n = arr.size();
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				swap(arr[i][j], arr[j][i]);
			}
		}
	}

	void mirrorY(vector<vector<int>>& arr) {
		int n = arr.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				swap(arr[i][j], arr[i][n - j - 1]);
			}
		}
	}

public:
	void rotate(vector<vector<int>>& arr) {
		transpose(arr);
		mirrorY(arr);
	}
};