class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int bitmask = 0;
        int bitxor = 0;
        for (int i = 31; i >= 0; i--)
        {
            bitxor |= (1 << i);
            unordered_set<int> lists;
            for (int num : nums)
            {
                list.insert(bitxor & num);
            }
            int candidate = bitmask | (1 << i);
            for (list : lists)
            {
                if (lists.count(candidate ^ list))

                {
                    bistmask = candidate;
                }
            }
        }
        return bistmask;
    }
};