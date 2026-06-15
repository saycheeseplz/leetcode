class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<int> result;
        result.reserve(n * m); // tránh resize nhiều lần

        for (int s = 0; s <= n + m - 2; s++)
        {
            if (s % 2 == 0)
            { // đi lên phải
                int i = min(s, n - 1);
                int j = s - i;
                while (i >= 0 && j < m)
                {
                    result.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }
            else
            { // đi xuống trái
                int j = min(s, m - 1);
                int i = s - j;
                while (i < n && j >= 0)
                {
                    result.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
        }

        return result;
    }
};
