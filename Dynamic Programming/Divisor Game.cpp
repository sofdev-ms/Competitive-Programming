https://leetcode.com/problems/divisor-game/

class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N + 1];
        dp[1] = false;
        dp[0] = true;
        for(int i = 2; i <= N;i ++)
        {
            dp[i] = false;
            for(int j = 1; j * j <= i; j ++)
            {
                if(i % j == 0)
                {
                    dp[i] |= !dp[i - j];
                    dp[i] |= !dp[i - i / j];
                }
            }
        }
        return dp[N];
    }
};
