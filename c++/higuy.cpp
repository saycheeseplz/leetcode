void kth(BSTNode *node, int &val, int k, int &index)
{
    if (!node)
    {
        return;
    }
    kth(node->left, val, K, index);
    if (k == index)
    {
        val = node->val;
        return;
    }
    index++;
    kth(node->right, val, k, index);
}
int kthSmallest(BSTNode *root, int k)
{
    // STUDENT ANSWER
    int data = 0;
    int index = 1;
    kth(root, data, k, index);
    return data;
}