class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // dp[i][j] = số chuỗi tối đa có thể chọn với i số '0' và j số '1'
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto &s : strs)
        {
            int zeros = 0, ones = 0;
            for (char c : s)
            {
                if (c == '0')
                    zeros++;
                else
                    ones++;
            }

            // Cập nhật DP ngược để tránh ghi đè dữ liệu
            for (int i = m; i >= zeros; --i)
            {
                for (int j = n; j >= ones; --j)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        return dp[m][n];
    }
};
