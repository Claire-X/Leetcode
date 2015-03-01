//DP
//global[i][j]表示第i天最多进行j次交易的情况，global[i][j]=max(global[i-1][j],local[i][j])，即将global分为两种情况，第i天
//进行了交易local[i][j]和第i天没有进行交易global[i-1][j]
//local[i][j]也可分为两种情况，情况一是多做的一次交易在第i-1天和i天之间进行global[i-1][j-1]+diff，情况二是多做的一次交易
//在小于i-1的某天和第i天之间进行local[i-1][j]+diff，翻译为把locallocal[i-1][j]中第i-1天的交易挪到第i天进行，产生的收益差加
//上diff即可，如果在把另外一天的交易挪到i天能产生的收益差更大，则说明挪到i-1天也会最大，那么和local[i-1][j]的定义矛盾。
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int days = prices.size();
        if(k>=days-1) return maxProfit(prices);
        int global[days][k+1];
        int local[days][k+1];
        fill_n(&global[0][0],k+1,0);
        fill_n(&local[0][0],k+1,0);
        for(int i =1;i<days;i++){
            local[i][0]=0;
            global[i][0]=0;
            for(int j = 1;j<k+1;j++){
                int diff = prices[i]-prices[i-1];
                local[i][j]=max(global[i-1][j-1]+diff,local[i-1][j]+diff);
                global[i][j]=max(global[i-1][j],local[i][j]);
            }
        }
        return global[days-1][k];
        
    }
    
    int maxProfit(vector<int> &prices) {
        int profit=0;
        for(size_t i =1;i<prices.size();i++){
           if(prices[i]>prices[i-1]) 
                profit+=prices[i]-prices[i-1];
        }
        return profit;
    }
};
