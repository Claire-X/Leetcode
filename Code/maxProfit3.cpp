//DP
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1) return 0;
        int n = prices.size(),minP = prices[0],maxP=prices[n-1],profit=0;
        int left[n];
        int right[n];

        for(int i =0;i<n;i++){
           profit=max(prices[i]-minP,profit);
           left[i]=profit;
           if(minP>prices[i]) minP = prices[i];
        }
        int result=INT_MIN;
        profit = 0;
        for(int i=n-1;i>=0;i--){
            profit = max(maxP- prices[i],profit);
            result =max(result,left[i]+profit);
            if(maxP<prices[i]) maxP = prices[i];
        }
        return result;
    }
};
