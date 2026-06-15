class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        for (int c : coins)
        {
            for (int j = c; j <= amount; j++)
            {
                dp[j] += dp[j - c];
            }
        }
        return dp[amount];
    }
};