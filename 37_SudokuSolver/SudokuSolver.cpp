// LeetCode : 37 - Sudoko Solver (https://leetcode.com/problems/sudoku-solver/description/)
// TUF+ : Sudoko Solver (https://takeuforward.org/plus/dsa/problems/sudoko-solver)

/*
Topics and Learnings: Recursion

Approach:
Used Recursion to solve this

Complexity Analysis:
TC: (9^(N*N))
SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		solve(board);
	}

private:
	bool solve(vector<vector<char>>& board) {
		int n = 9;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '.') {
					for (char digit = '1'; digit <= '9'; digit++) {
						if (areRulesMet(board, i, j, digit)) {
							board[i][j] = digit;
							if (solve(board)) {
								return true;
							}
							else {
								board[i][j] = '.';
							}
						}
					}
					return false;
				}
			}
		}
		return true;
	}

	bool areRulesMet(vector<vector<char>>& board, int row, int col, char digit) {
		for (int i = 0; i < 9; i++) {
			if (board[row][i] == digit || board[i][col] == digit) {
				return false;
			}
		}
		int startRow = (row / 3) * 3;
		int startCol = (col / 3) * 3;
		for (int i = startRow; i < startRow + 3; i++) {
			for (int j = startCol; j < startCol + 3; j++) {
				if (board[i][j] == digit) {
					return false;
				}
			}
		}
		return true;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		vector<vector<char>> board;
		vector<char> row;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char input;
				cin >> input;
				row.push_back(input);
			}
			board.push_back(row);
		}

		Solution sol;
		sol.solveSudoku(board);

		for (const auto row : board) {
			for (char c : row) {
				cout << c << " ";
			}
			cout << endl;
		}
	}

	return 0;
}

/*
TestInput:

TestOutput:

*/
