class Solution
{
public:
    int dfs(const vector<int> &nums, int l, int r, vector<vector<int>> &memo)
    {
        if (l == r)
            return nums[l];
        if (memo[l][r] != INT_MIN)
            return memo[l][r];
        int pickLeft = nums[l] - dfs(nums, l + 1, r, memo);
        int pickRight = nums[r] - dfs(nums, l, r - 1, memo);
        memo[l][r] = max(pickLeft, pickRight);
        return memo[l][r];
    }

    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return true;
        vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
        return dfs(nums, 0, n - 1, memo) >= 0;
    }
};
