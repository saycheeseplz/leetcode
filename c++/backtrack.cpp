class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums2.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums2[i]] = i;
        }
        vector<int> result;
        for (int num : nums1)
        {
            int target = -1;
            int i = mp[num] + 1;
            for (i; i < n; i++)
            {
                if (nums2[i] > num)
                {
                    target = nums2[i];
                    break;
                }
            }
            result.push_back(target);
        }
        return result;
    }
};