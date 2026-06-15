class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int total = 0;
        int curMax = 0, maxSum = INT_MIN;
        int curMin = 0, minSum = INT_MAX;

        for (int x : nums)
        {
            total += x;

            // max subarray normal (Kadane)
            curMax = max(x, curMax + x);
            maxSum = max(maxSum, curMax);

            // min subarray normal
            curMin = min(x, curMin + x);
            minSum = min(minSum, curMin);
        }

        // nếu toàn bộ nums đều negative => vòng tròn sẽ trả ra 0, sai
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};
