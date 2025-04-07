// LeetCode : 121 - Best Time to Buy and Sell Stock (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)
// TUF+ : Best time to buy and sell stock (https://takeuforward.org/plus/dsa/dynamic-programming/dp-on-stocks/best-time-to-buy-and-sell-stock)

/*
Topics and Learnings:

Approach:
Used Linear Traversal to solve this

Complexity Analysis:
TC: O(N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int min = prices[0];
		int profit = 0;
		for (int i = 1; i < prices.size(); i++) {
			int current = prices[i];
			if (current < min)
				min = current;
			else if (profit < current - min)
				profit = current - min;
		}
		return profit;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> arr;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			arr.push_back(input);
		}

		Solution sol;

		int res = sol.maxProfit(arr);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
3

6
10 7 5 8 11 9

5
5 4 3 2 1

6
3 8 1 4 6 2

Test Output : 1
6
0
5

*/
