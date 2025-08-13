/*
Author : @wuan
Link :
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define endl '\n'
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int rob(TreeNode *root)
{
    int prev = 0;
    int cur = 0;
    queue<TreeNode *> q;
    while (!q.empty())
    {
        int n = q.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            sum += temp->val;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        int last = cur;
        cur = max(cur, prev + sum);
        prev = last;
    }
    return cur;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << rob(root);
    return 0;
}