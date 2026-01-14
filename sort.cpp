void backtrack(BTNode *root, int cur, int &max_val, mod)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        cur *= 10;
        cur %= mod;
        int a = root->val % mod;
        cur += a;
        cur %= mod;
        max_val += cur;
        max_val % mod;
        return;
    }
    cur *= 10;
    int a = (root->val) % mod;
    cur = (cur + a) % mod;
    backtrack(root->left, cur, max_val, mod);
    backtrack(root->right, cur, max_val, mod);
}
int sumDigitPath(BTNode *root)
{
    int max_val = 0;
    int mod = 27022001;
    backtrack(root, 0, max_val, mod);
    return max_val;
}