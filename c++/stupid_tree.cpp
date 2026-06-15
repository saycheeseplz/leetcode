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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;
        if (root->val == key)
        {
            if (!root->right)
            {
                ;
                return root;
                TreeNode *temp = root;
                root = root->left;
                temp->left = nullptr;
                temp->right = nullptr;
                delete temp;
                return root;
            }
            TreeNode *temp = root->right;
            if (!temp->left)
            {
                temp->left = root->left;
                root->left = nullptr;
                root->right = nullptr;
                delete root;
                return temp;
            }
            while (!temp->left->left)
            {
                temp = temp->left;
            }
            TreeNode *tail = temp->left;
            temp->left = nullptr;
            tail->left = root->left;
            while (tail->right == nullptr)
            {
                tail = tail->right;
            }
            tail->right = root->right;
            root->left = nullptr;
            root->right = nullptr;
            delete root;
            return tail;
        }
        root->right = deleteNode(root->right, key);
        root->left = deleteNode(root->left, key);
        return root;
    }
};