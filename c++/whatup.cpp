#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMoneyAmount(int n)
    {
        if (n <= 1)
            return 0;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 1; i + len - 1 <= n; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k)
                { // chỉ cần xét ở giữa
                    int cost = k + max(dp[i][k - 1], dp[k + 1][j]);
                    dp[i][j] = min(dp[i][j], cost);
                }
                // nếu khoảng chỉ có 2 số thì chỉ cần chọn số nhỏ hơn
                if (len == 2)
                    dp[i][j] = i;
            }
        }
        return dp[1][n];
    }
};
