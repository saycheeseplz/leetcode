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
    bool predict(vector<int> &nums, int start, int end, int total, int turn, unordered_map<int, bool> mp)
    {
        int x = start * 1000 + end;
        if (mp.count(x))
        {
            return mp[x];
        }
        if (start == end)
        {
            total += turn * nums[start];
            bool check = total >= 0;
            check = turn == 1 ? check : !check;

            return check;
        }

        bool check = (predict(nums, start + 1, end, total + nums[start] * turn, turn * -1, mp) |
                      predict(nums, start, end - 1, total + nums[end] * turn, turn * -1, mp));
        check = turn == 1 ? check : !check;
        if (check)
        {
            return mp[x] = true;
        }
        return mp[x] = false;
    }

    bool predictTheWinner(vector<int> &nums)
    {
        unordered_map<int, bool> mp;
        int n = nums.size() - 1;
        return predict(nums, 0, n, 0, 1, mp);
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nums({1, 5, 2});
    Solution b;
    cout << b.predictTheWinner(nums);
    return 0;
}