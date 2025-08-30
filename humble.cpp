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
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;
        for (int num : nums)
        {
            int idx = nums[abs(num) - 1];
            if (idx < 0)
            {
                result.push_back(abs(num));
            }
            else
            {
                nums[abs(num) - 1] = idx * -1;
            }
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
    vector<int> nums({4, 3, 2, 7, 8, 2, 3, 1, 1});
    vector<int>
        a = b.findDuplicates(nums);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}