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
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int backtrack(TreeNode *root, unordered_map<int, int> &mp, int left, int right)
    {
        if (!root)
        {
            return 0;
        }
        int l = backtrack(root->left, mp, left, right);
        int r = backtrack(root->right, mp, left, right);
        int moderate = l + r + root->val;
        mp[moderate]++;
        return moderate;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        unordered_map<int, int> mp;
        int temp = backtrack(root, mp, 0, 0);
        temp = 0;
        for (auto it : mp)
        {
            if (it.second > temp)
            {
                temp = it.second;
            }
        }
        vector<int> result;
        for (auto it : mp)
        {
            if (it.second == temp)
            {
                result.push_back(it.first);
            }
        }
        return result;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution b;
    vector<int> a;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);
    a = b.findFrequentTreeSum(root);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}