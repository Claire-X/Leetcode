class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() == 0)
			return 0;
		int buy = -1, sell = -1, profit = 0;
		int i = 0, n = prices.size();
		while (i < n - 1) {
			while (i < n - 1 && prices[i] > prices[i + 1])
				i++;
			if (i < n)
				buy = i;
			else
				break;
			while (i < n - 1 && prices[i] < prices[i + 1])
				i++;
			if (i < n)
				sell = i;
			else
				break;
			if (buy >= 0 && sell >= 0)
				profit += (prices[sell] - prices[buy]);
			sell = -1;
			buy = -1;
			if (i < n - 1)
				i++;
			else
				break;
		}
		if (buy >= 0)
			profit += prices.back() - prices[buy];
		return profit;
	}
};
