class Solution
{
public:
    int getMoneyAmount(int n)
    {
        // dp[i][j] = chi phí ít nhất để chắc chắn đoán đúng trong khoảng [i, j]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len <= n; ++len)
        {
            for (int start = 1; start + len - 1 <= n; ++start)
            {
                int end = start + len - 1;
                dp[start][end] = INT_MAX;

                for (int piv = start; piv <= end; ++piv)
                {
                    int cost = piv + max((piv - 1 >= start ? dp[start][piv - 1] : 0),
                                         (piv + 1 <= end ? dp[piv + 1][end] : 0));
                    dp[start][end] = min(dp[start][end], cost);
                }
            }
        }

        return dp[1][n];
    }
};
