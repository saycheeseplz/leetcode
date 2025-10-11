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

vector<vector<int>> dp(8, vector<int>(8, 0));
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {

        int n = s.size();

        // vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                if (i > j)
                {
                    break;
                }
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
                    dp[i][j] = dp[i + 1][j - 1];
                    if (s[i] == s[j])
                    {
                        dp[i][j] += 2;
                    }
                    else
                    {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[n - 1][n - 1];
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution b;
    cout << b.longestPalindromeSubseq("agbdbaaa");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}