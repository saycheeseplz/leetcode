class Solution
{
private:
    int minn = INT_MAX;
    TreeNode *prev = nullptr;

public:
    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        if (prev)
            minn = min(minn, root->val - prev->val);

        prev = root;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        inorder(root);
        return minn;
    }
};
