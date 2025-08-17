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
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> pa;
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> add;
        pa.push_back({nums1[0], nums2[0]});
        add[0]++;
        int quantity = 1;
        while (quantity < k)
        {
            int min_value = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                if (min_value < nums1[i])
                {
                    break;
                }
                if (add[i] != m)
                {
                    min_value = min(min_value, nums1[i] * nums2[add[i]]);
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (add[i] != m)
                {
                    if (min_value == nums1[i] * nums2[add[i]])
                    {
                        pa.push_back({nums1[i], nums2[add[i]]});

                        add[i]++;
                        quantity++;
                        break;
                    }
                }
            }
        }
        return pa;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> a;
    Solution b;
    vector<int> nums1({1, 1, 7, 11, 16});
    vector<int> nums2({1, 1, 7, 11, 16});
    a = b.kSmallestPairs(nums1, nums2, 3);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}