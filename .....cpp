class Solution
{
public:
    int count(vector<int> &num, int target, int total, int start)
    {
        int n = num.size();
        if (start == n)
        {
            if (target == total)
                return 1;
            return 0;
        }
        int val = 0;
        for (int i = start, i < n; i++)
        {
            val += count(num, target, total + num[i], i + 1);
            val += count(num, target, total - num[i], i + 1);
        }
        return val;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return count(num, target, 0, 0);
    }
};