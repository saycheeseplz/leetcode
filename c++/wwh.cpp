/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<int> result;
        while (!q.empty())
        {
            int n = q.size();
            int max_cur = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                max_cur = max(temp->val, max_cur);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            result.push_back(max_cur);
        }
        return result;
    }
};