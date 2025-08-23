struct TreeNode
{
    TreeNode *path[2];
    TreeNode() : path{nullptr, nullptr} {}
};

class Solution
{
private:
    void insert(TreeNode *root, int num, int bits)
    {
        for (int i = bits - 1; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!root->path[bit])
            {
                root->path[bit] = new TreeNode();
            }
            root = root->path[bit];
        }
    }

    int find_max(TreeNode *root, int num, int bits)
    {
        int maxxor = 0;
        for (int i = bits - 1; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            int trade_off = bit ^ 1;
            if (root->path[trade_off])
            {
                maxxor |= (1 << i);
                root = root->path[trade_off];
            }
            else
            {
                root = root->path[bit];
            }
        }
        return maxxor;
    }

public:
    int findMaximumXOR(vector<int> &nums)
    {
        int num_max = *max_element(nums.begin(), nums.end());
        if (num_max == 0)
            return 0;

        int bit_count = count_bits(num_max);
        TreeNode *root = new TreeNode();

        for (int num : nums)
        {
            insert(root, num, bit_count);
        }

        int max_xor = 0;
        for (int num : nums)
        {
            max_xor = max(max_xor, find_max(root, num, bit_count));
        }
        return max_xor;
    }

    int count_bits(int num)
    {
        int count = 0;
        while (num > 0)
        {
            count++;
            num >>= 1;
        }
        return max(count, 1);
    }
};
