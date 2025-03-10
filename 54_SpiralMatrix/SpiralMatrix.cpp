// LeetCode : 54 - Spiral Matrix (https://leetcode.com/problems/spiral-matrix/description/)
// TUF+ : Print the matrix in spiral manner (https://takeuforward.org/plus/dsa/arrays/faqs-medium/print-the-matrix-in-spiral-manner)

/*
Topics and Learnings:

Approach:
Used four separate loops to print the array elements in spiral

Complexiy Analysis:
TC: O(M * N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// More Readable Solution
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;

		int rows = matrix.size();
		int cols = matrix[0].size();

		int top = 0, bottom = rows - 1;
		int left = 0, right = cols - 1;

		while (top <= bottom && left <= right) {
			for (int i = left; i <= right; i++)
				result.push_back(matrix[top][i]);

			top++;

			for (int i = top; i <= bottom; i++)
				result.push_back(matrix[i][right]);

			right--;

			if (top <= bottom) {
				for (int i = right; i >= left; i--)
					result.push_back(matrix[bottom][i]);
				bottom--;
			}


			if (left <= right) {
				for (int i = bottom; i >= top; i--)
					result.push_back(matrix[i][left]);
				left++;
			}
		}

		return result;
	}

	// Less Readable Approach
	vector<int> spiralOrder2(vector<vector<int>>& matrix) {
		vector<int> result;
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int i = 0; i < rows / 2 && i < cols / 2; i++) {
			int n = rows - (2 * i);
			int m = cols - (2 * i);

			for (int j = i; j < m + i; j++)
				result.push_back(matrix[i][j]);

			for (int j = i + 1; j < n + i; j++)
				result.push_back(matrix[j][m + i - 1]);

			for (int j = m + i - 2; j >= i; j--)
				result.push_back(matrix[n + i - 1][j]);

			for (int j = n + i - 2; j > i; j--)
				result.push_back(matrix[j][i]);
		}
		if (cols > rows && rows % 2 != 0)
			for (int i = rows / 2; i <= cols - 1 - (rows / 2); i++)
				result.push_back(matrix[rows / 2][i]);

		else if (rows > cols && cols % 2 != 0)
			for (int i = cols / 2; i <= rows - 1 - (cols / 2); i++)
				result.push_back(matrix[i][cols / 2]);

		else if (rows == cols && cols % 2 != 0)
			result.push_back(matrix[rows / 2][cols / 2]);

		return result;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int m, n;
		cin >> m >> n;

		vector<vector<int>> matrix;

		for (int i = 0; i < m; i++) {
			vector<int> arr;
			for (int j = 0; j < n; j++) {
				int input;
				cin >> input;
				arr.push_back(input);
			}
			matrix.push_back(arr);
		}

		Solution sol;

		vector<int> res = sol.spiralOrder(matrix);

		for (auto i : res) {
			cout << i << " ";
		}

		cout << endl;
	}

	return 0;
}

/*
Test Input :
3

3 3
1 2 3
4 5 6
7 8 9

2 4
1 2 3 4
5 6 7 8

4 2
1 2
3 4
5 6
7 8

Test Output :
1 2 3 6 9 8 7 4 5
1 2 3 4 8 7 6 5
1 2 4 6 8 7 5 3

*/
