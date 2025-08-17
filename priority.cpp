class Solution
{
public:
    struct cmd
    {
        bool operator()(array<int, 3> const a, array<int, 3> const b) const
        {
            return a[0] > b[0];
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, cmd> pa;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            pa.push({(nums1[i] + nums2[0]), nums1[i], 0});
        }
        vector<vector<int>> result;
        while (count < k && !pa.empty())
        {
            auto top = pa.top();
            int num = top[1];
            int nums = nums2[top[2]];
            pa.pop();
            result.push_back({num, nums});
            if (top[2] < m - 1)
            {
                pa.push({num + nums2[top[2] + 1], num, top[2] + 1});
            }
            count++;
        }
        return result;
    }
};