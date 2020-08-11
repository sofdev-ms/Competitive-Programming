https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 0)
            return 0;
        else if(size == 1)
            return nums[0];
        
        int dp[size];
        dp[0] = nums[0];
        dp[1] = max(nums[1] ,nums[0]);
        for(int i = 2; i < size; i ++)
        {
            dp[i] = max(dp[i - 1] , nums[i] + dp[i - 2]);  
        }
        
        return dp[size - 1];
        
    }
};
