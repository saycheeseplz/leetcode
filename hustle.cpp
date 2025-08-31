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
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return false;

        stack<int> st;       // giữ ứng viên cho "2"
        int third = INT_MIN; // ứng viên cho "3"

        // duyệt từ phải sang trái
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < third)
            {
                return true; // nums[i] = "1", third = "3", stack có "2"
            }
            while (!st.empty() && nums[i] > st.top())
            {
                // pop ra và cập nhật "3"
                third = st.top();
                st.pop();
            }
            st.push(nums[i]); // nums[i] có thể là "2"
        }
        return false;
    }
};
