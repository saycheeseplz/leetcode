class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xorAll = 0;
        for (int num : nums)
        {
            xorAll ^= num;
        }

        // An toàn tuyệt đối:
        unsigned int ux = xorAll;
        unsigned int diffBit = ux & -ux;

        int x = 0, y = 0;
        for (int num : nums)
        {
            if (num & diffBit)
            {
                x ^= num;
            }
            else
            {
                y ^= num;
            }
        }

        return {x, y};
    }
};
