#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(vector<int> &sticks, vector<int> &sides, int idx, int target)
    {
        if (idx == sticks.size())
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;

        for (int i = 0; i < 4; i++)
        {
            // prune: nếu đặt que vào cạnh i vượt target thì bỏ
            if (sides[i] + sticks[idx] > target)
                continue;

            // symmetry breaking: nếu cạnh i bằng cạnh trước đó chưa đặt que thì bỏ
            if (i > 0 && sides[i] == sides[i - 1])
                continue;

            sides[i] += sticks[idx];
            if (dfs(sticks, sides, idx + 1, target))
                return true;
            sides[i] -= sticks[idx];
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
            return false;

        int side = sum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend()); // sort giảm dần để prune nhanh

        if (matchsticks[0] > side)
            return false;

        vector<int> sides(4, 0);
        return dfs(matchsticks, sides, 0, side);
    }
};
