class Solution
{
public:
    void backtrack(TreeNode *root, string &path, vector<string> &result)
    {
        if (!root)
            return;

        int len = path.length();
        path += to_string(root->val);
        if (!root->left && !root->right)

        {
            result.push_back(path);
        }
        else
        {
            path += "->";
            backtrack(root->left, path, result);
            backtrack(root->right, path, result);
        }

        path.resize(len); // "backtrack" chuỗi về trạng thái ban đầu
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        string path;
        backtrack(root, path, result);
        return result;
    }
};
