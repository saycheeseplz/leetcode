class Solution
{
public:
    int dfs(TreeNode *root, unordered_map<int, int> &freq, int &maxFreq)
    {
        if (!root)
            return 0;
        int sum = root->val + dfs(root->left, freq, maxFreq) + dfs(root->right, freq, maxFreq);
        maxFreq = max(maxFreq, ++freq[sum]);
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        dfs(root, freq, maxFreq);

        vector<int> result;
        for (auto &[sum, count] : freq)
        {
            if (count == maxFreq)
                result.push_back(sum);
        }
        return result;
    }
};
