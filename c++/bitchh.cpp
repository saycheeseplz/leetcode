class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        long long ans = 0;
        int n = (int)nums.size();
        for (int b = 0; b < 31; ++b)
        { // 31 bit đủ cho 1e9; 32 cũng OK
            int ones = 0;
            for (int x : nums)
                ones += (x >> b) & 1;
            ans += 1LL * ones * (n - ones);
        }
        return (int)ans; // LeetCode yêu cầu int, nhưng tính bằng 64-bit
    }
};
