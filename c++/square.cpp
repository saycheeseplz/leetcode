class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX); // dp[i]: số ít nhất các số chính phương để tạo thành i
        dp[0] = 0;                      // Tổng bằng 0 thì không cần số nào

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
class Solution
{
public:
    unordered_map<int, int> memo;
    int dfs(int n)
    {
        if (n == 0)
            return 0;
        if (memo.count(n))
            return memo[n];
        int res = INT_MAX;
        for (int i = 1; i * i <= n; ++i)
        {
            res = min(res, dfs(n - i * i) + 1);
        }
        return memo[n] = res;
    }
    int numSquares(int n)
    {
        return dfs(n);
    }
};
