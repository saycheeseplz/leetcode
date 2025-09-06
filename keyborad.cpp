class Solution
{
public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> result;
        TreeNode *prev = nullptr;
        int count = 0, maxCount = 0;
        inorder(root, prev, count, maxCount, result);
        return result;
    }

    void inorder(TreeNode *node, TreeNode *&prev, int &count, int &maxCount, vector<int> &result)
    {
        if (!node)
            return;
        inorder(node->left, prev, count, maxCount, result);

        if (prev && prev->val == node->val)
            count++;
        else
            count = 1;

        if (count > maxCount)
        {
            maxCount = count;
            result.clear();
            result.push_back(node->val);
        }
        else if (count == maxCount)
        {
            result.push_back(node->val);
        }

        prev = node;
        inorder(node->right, prev, count, maxCount, result);
    }
};
