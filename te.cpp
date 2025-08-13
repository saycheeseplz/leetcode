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
int find_idx(vector<int> &a, int l, int r, int target)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (target == a[m])
        {
            return m;
        }
        else if (target < a[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}
bool increasingTriplet(vector<int> &nums)
{
    vector<int> a;
    a.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        int n = a.size() - 1;
        if (nums[i] > a[n])
        {
            a.push_back(nums[i]);
            if (n + 1 == 3)
            {
                return true;
            }
        }
        else
        {
            int idx = find_idx(a, 0, n, nums[i]);
            a[idx] = nums[i];
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> nums({2, 1, 5, 4, 6});
    cout << increasingTriplet(nums);
    return 0;
}