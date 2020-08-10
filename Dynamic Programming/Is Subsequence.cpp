https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = s.length();
        int m = t.length();
        
        int i = 0;
        int j = 0;
        while( i < l && j < m)
        {
            if(s[i] == t[j])
                i++;
            
            j++;
        }
        
        return i == l;
        
    }
};
