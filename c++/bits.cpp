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
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int num : nums)
    {
        mp[num]++;
    }
    vector<pair<int, int>> pa;
    for (auto it : mp)
    {
        pa.push_back({it.second, it.first});
    }
    sort(pa.begin(), pa.end());
    vector<int> a;
    for (int i = 0; i < k; i++)
    {
        a.push_back(pa[i].second);
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> nums({1, 1, 1, 2, 2, 3});
    vector<int> a = topKFrequent(nums, 2);
    return 0;
}