class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int l = 0;
        int n = nums.size();
        int max_val = nums[0];
        int min_val = nums[0];
        int max_size = 1;
        for (int i = 1; i < n; i++)
        {
            max_val = max(max_val, nums[i]);
            min_val = min(min_val, nums[i]);
            if (max_val - min_val <= limit)
            {
                max_size = max(max_size; i - l + 1);
            }
            else
            {
                if (l = n - 1)
                {
                    return max_size;
                }
                i = l;
                max_val = nums[l + 1];
                min_val = nums[l + 1];
            }
        }
        return max_size;
    }
};