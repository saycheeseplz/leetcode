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
    string predictPartyVictory(string senate)
    {
        int count_r = 0;
        int count_d = 0;
        queue<char> q;
        int n = senate.size();
        for (int i = 0; i < n; i++)
        {
            q.push(senate[i]);
        }
        while (!(q.size() <= count_d || q.size() <= count_r))
        {

            char c = q.front();
            q.pop();
            if (c == 'D')
            {
                if (count_d > 0)
                {
                    count_d--;
                    continue;
                }
                else
                {
                    count_r++;
                    q.push(c);
                }
            }
            else
            {
                if (count_r > 0)
                {
                    count_r--;
                    continue;
                }
                else
                {
                    count_d++;
                    q.push(c);
                }
            }
        }
        return count_d == 0 ? "Dire" : "Radiant";
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution b;
    cout << b.predictPartyVictory("RD");

    return 0;
}