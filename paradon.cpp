/*
Author : @wuan
Link :
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define endl '\n'
vector<vector<int>> dp;
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        if (n <= 1)
        {
            return n;
        }
        dp = vector<vector<int>>(n, vector<int>(n, 0));

        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = len + i - 1;
                if (len == 1)
                {
                    dp[i][j] = 1;
                }
                else if (len == 2)
                {
                    dp[i][j] = 1;
                    if (s[i] == s[j])
                    {
                        dp[i][j]++;
                    }
                }
                else
                {

                    if (s[i] == s[j])
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                    else
                    {
                        int k = 1;
                        while (i + k < n && s[k + i] != s[j] && dp[i][i + k] == 1)
                        {
                            k++;
                        }
                        if (i + k < n && s[k + i] == s[j] && dp[i][i + k] == 1)
                        {
                            dp[i][j] = dp[i + 1][j - 1] + 2;
                        }
                    }
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution b;
    cout << b.longestPalindromeSubseq("cbbd") << endl;
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}