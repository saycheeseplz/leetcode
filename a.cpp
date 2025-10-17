class Solution
{
public:
    int n;
    vector<vector<int>> memo;

    int backtrack(int pos, int mask)
    {
        if (pos > n)
            return 1;
        if (memo[pos][mask] != -1)
            return memo[pos][mask];

        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!(mask & (1 << i)))
            { // nếu i chưa dùng
                if (pos % i == 0 || i % pos == 0)
                {
                    count += backtrack(pos + 1, mask | (1 << i));
                }
            }
        }
        return memo[pos][mask] = count;
    }

    int countArrangement(int n)
    {
        this->n = n;
        memo = vector<vector<int>>(n + 1, vector<int>(1 << (n + 1), -1));
        return backtrack(1, 0);
    }
};
