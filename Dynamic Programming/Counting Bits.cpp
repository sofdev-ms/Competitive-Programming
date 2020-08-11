https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector < int > ans;
        ans.push_back(0);
        int curr = 1;
        for(int i = 1; i <= num ; i ++)
        {
            if(i == curr * 2)
                curr *= 2;
            ans.push_back( 1 + ans[i - curr]);
            
            
        }
        return ans;
    }
};
