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
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[equations[i][0]].push_back({equations[i][1],
                                           values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        double value = -1;
        function<void(string, string, double, unordered_map<string, bool>)> path = [&](string start, string end, double val, unordered_map<string, bool> pre)
        {
            if (value != -1)
                return;
            if (start == end)
            {
                value = val;
                return;
            }
            pre[start] = true;
            for (auto neighbor : mp[start])
            {
                if (pre[neighbor.first] == 0)
                {
                    path(neighbor.first, end, val * neighbor.second, pre);
                }
            }
        };
        vector<double> result;
        for (vector que : queries)
        {
            value = -1;
            unordered_map<string, bool> pre;
            path(que[0], que[1], 1.0, pre);
            result.push_back(value);
        }
        return result;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution b;
    vector<vector<string>> queries = {
        // {"a", "c"},
        // {"b", "a"},
        // {"a", "e"},
        // {"a", "a"},
        {"x", "x"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> equation = {
        {"a", "b"},
        {"b", "c"}};
    b.calcEquation(equation, values, queries);

    return 0;
}