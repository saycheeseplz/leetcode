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

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        queue<pair<int, int>> share, wait;
        share.push({1, 1});
        int quantity = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i - share.front().first >= forget)
            {
                quantity -= share.front().second;
                share.pop();
            }
            wait.push({i, quantity});
            if (!wait.empty() && i - wait.front().first >= delay)
            {
                pair<int, int> x = wait.front();
                wait.pop();
                share.push(x);
                quantity += x.second;
            }
        }
        return quantity;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution b;
    cout << b.peopleAwareOfSecret(4, 1, 3);

    return 0;
}