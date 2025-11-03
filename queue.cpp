class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        queue<int> point_max, point_min;
        int max_size = 0;
        int n = nums.size();
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            while (!point_max.empty() && point_max.back() <= nums[i])
            {
                point_max.pop();
            }
            point_max.push(nums[i]);
            while (!point_min.empty() && point_min.back() >= nums[i])
            {
                point_min.pop();
            }
            point_min.push(nums[i]);
            while (point_max.front() - point_min.front() > limit)
            {
                if (point_max.front() == nums[l])
                {
                    point_max.pop();
                }
                if (point_min.front() == nums[l])
                {
                    point_min.pop();
                }
                l++;
            }
            max_size = max(max_size, i - l + 1);
        }
        return max_size;
    }
};