https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int present = nums[0];
        int mx = nums[0];
        for(int i = 1 ; i < size; i ++)
        {
            present = max(present + nums[i] , nums[i]);
            mx = max(present , mx);
        }
        return mx;
    }
};
