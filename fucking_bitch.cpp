class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        function<int(int, int)> dfs = [&](int x, int y)
        {
            int count = 0;
            grid[x][y] = 2; // đánh dấu đã duyệt
            for (auto &d : dirs)
            {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 0)
                    count++;
                else if (grid[nx][ny] == 1)
                    count += dfs(nx, ny);
            }
            return count;
        };

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1)
                    return dfs(i, j);

        return 0;
    }
};
