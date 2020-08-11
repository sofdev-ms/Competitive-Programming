https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
    int pre[10001];
    NumArray(vector<int>& nums) {
        int size = nums.size();
        pre[0] = 0;
        for(int i = 1; i <= size; i ++)
            pre[i] = pre[i - 1] + nums[i - 1];
    }
    
    int sumRange(int i, int j) {
        return pre[j + 1] - pre[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
