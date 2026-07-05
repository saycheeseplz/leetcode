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
    // Serialize helper: preorder traversal
    void serializeHelper(TreeNode *root, std::stringstream &ss)
    {
        if (!root)
        {
            ss << "null,";
            return;
        }
        ss << root->val << ",";
        serializeHelper(root->left, ss);
        serializeHelper(root->right, ss);
    }

    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root)
    {
        std::stringstream ss;
        serializeHelper(root, ss);
        return ss.str();
    }

    // Deserialize helper: parse string directly using index
    TreeNode *deserializeHelper(const std::string &data, int &i)
    {
        if (i >= data.size())
            return nullptr;

        if (data[i] == 'n')
        {           // "null"
            i += 5; // skip "null,"
            return nullptr;
        }

        // Read number (support negative and multiple digits)
        int sign = 1;
        if (data[i] == '-')
        {
            sign = -1;
            i++;
        }
        int val = 0;
        while (i < data.size() && isdigit(data[i]))
        {
            val = val * 10 + (data[i] - '0');
            i++;
        }
        i++; // skip ','

        TreeNode *root = new TreeNode(val * sign);
        root->left = deserializeHelper(data, i);
        root->right = deserializeHelper(data, i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const std::string &data)
    {
        int index = 0;
        return deserializeHelper(data, index);
    }
};

// Usage:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// std::string treeStr = ser->serialize(root);
// TreeNode* newRoot = deser->deserialize(treeStr);
