class Solution
{
public:
    vector<int> dx{-1, 0, 0, 1};
    vector<int> dy{0, -1, 1, 0};

    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // Đưa tất cả cam thối vào queue và đếm cam tươi
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0)
            return 0; // không có cam tươi

        int minutes = 0;

        while (!q.empty())
        {
            int sz = q.size();
            bool rotted = false; // kiểm tra có cam tươi nào bị thối trong bước này
            for (int i = 0; i < sz; i++)
            {
                auto [x0, y0] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++)
                {
                    int nx = x0 + dx[d];
                    int ny = y0 + dy[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if (rotted)
                minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
