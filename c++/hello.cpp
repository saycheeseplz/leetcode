int rangeCount(BTNode *root, int lo, int hi)
{
    if (!root)
    {
        return 0;
    }
    int count = 0;
    if (root->val >= lo && root->val <= hi)
    {
        count++;
    }
    if (root->val > lo)
    {
        count += rangeCount(root->left, lo, root->val);
    }
    if (root->val < hi)
    {
        count += rangeCount(root - right, root->val, hi);
    }
    return count;
}