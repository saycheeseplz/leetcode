/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
private:
    int getprefix(vector<vector<int>> &prefixsum, int ro, int co, int size)
    {
        return prefixsum[ro + size][co + size] - prefixsum[ro][co + size] - prefixsum[ro + size][co] + prefixsum[ro][co];
    }
    Node *build(vector<vector<int>> &prefixsum, int ro, int co, int size)
    {
        int sum = getprefix(prefixsum, ro, co, size);
        if (sum == 0)
        {
            return new Node(0, 1);
        }
        if (sum == size * size)
        {
            return new Node(1, 1);
        }

        int hard = size / 2;
        Node *tl = build(prefixsum, ro, co, hard);
        Node *tr = build(prefixsum, ro, co + hard, hard);
        Node *bl = build(prefixsum, ro + hard, co, hard);
        Node *br = build(prefixsum, ro + hard, co + hard, hard);
        return new Node(1, 0, tl, tr, bl, br);
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> prefixsum(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                prefixsum[i][j] = grid[i - 1][j - 1] + prefixsum[i - 1][j] + prefixsum[i][j - 1] - prefixsum[i - 1][j - 1];
            }
        }
        return build(prefixsum, 0, 0, n);
    }
};