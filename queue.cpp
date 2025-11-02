class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {

        deque<int> dqMax; // decreasing -> front = max
        deque<int> dqMin; // increasing -> front = min

        int l = 0, ans = 0;

        for (int r = 0; r < nums.size(); r++)
        {

            // maintain decreasing deque for max
            while (!dqMax.empty() && dqMax.back() < nums[r])
                dqMax.pop_back();
            dqMax.push_back(nums[r]);

            // maintain increasing deque for min
            while (!dqMin.empty() && dqMin.back() > nums[r])
                dqMin.pop_back();
            dqMin.push_back(nums[r]);

            // while violate
            while (dqMax.front() - dqMin.front() > limit)
            {
                // move left forward
                if (nums[l] == dqMax.front())
                    dqMax.pop_front();
                if (nums[l] == dqMin.front())
                    dqMin.pop_front();
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
