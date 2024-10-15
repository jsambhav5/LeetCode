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