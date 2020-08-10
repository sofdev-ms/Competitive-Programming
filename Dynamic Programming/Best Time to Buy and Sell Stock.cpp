https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int size = prices.size();
        if(size == 0)
            return ans;
        
        int mn = prices[0];
        
        for(int i = 1 ; i < size; i ++)
        {
            ans = max(ans , prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        
        return ans;
    }
};
