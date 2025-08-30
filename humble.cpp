/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.

    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string s = to_string(root->val);
        s += to_string(serialize(root->left));
        s += to_string(serialize(root->right));
        return s;
    }

    // Decodes your encoded data to tree.

    int depth_min(TreeNode *root)
    {
        return 1 + min(depth_min(root->left), depth_min(root->right));
    }
    void build(TreeNode *&root, int x)
    {
        if (!root)
        {
            TreeNode *temp = new TreeNode(x);
            temp->right = nullptr;
            temp->left = nullptr;
            root = temp;
        }
        else
        {
            int l = depth_min(root->left);
            int r = depth_min(root->right);
            if (l == r)
            {
                build(root->left, x);
            }
            else
                build(root->right, x);
        }
    }
    TreeNode *deserialize(string data)
    {
        TreeNode *root = nullptr;
        for (int i = 0; i < data.size(); i++)
        {
            int x = (data[i] - '0');
            build(root, x);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;