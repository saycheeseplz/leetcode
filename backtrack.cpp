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
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long long, int> mp;
        mp[0] = 1;
        return dfs(root, 0, targetSum, mp);
    }
    int dfs(TreeNode *root, long long Sumpath, int targetSum, unordered_map<long long, int> &mp)
    {
        if (!root)
            return 0;
        Sumpath += root->val;
        int count = 0;
        if (mp.count(Sumpath - targetSum))
        {
            count += mp[Sumpath - targetSum];
        }
        mp[Sumpath]++;
        count += dfs(root->left, Sumpath, targetSum, mp);
        count += dfs(root->right, Sumpath, targetSum, mp);
        mp[Sumpath]--;
        return count;
    }
};