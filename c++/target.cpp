class Solution
{
public:
    vector<int> dx{-1, 1, 0, 0};
    vector<int> dy{0, 0, -1, 1};

    void bfs(vector<vector<int>> &height, int environment, vector<vector<int>> &visited, queue<pair<int, int>> &evi, int n, int m)
    {
        while (!evi.empty())
        {
            int na = evi.size();
            for (int i = 0; i < na; i++)
            {
                pair<int, int> top = evi.front();
                evi.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nx = top.first + dx[k];
                    int ny = top.second + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && height[nx][ny] >= height[top.first][top.second] && !(visited[nx][ny] & environment))
                    {
                        visited[nx][ny] |= environment;
                        evi.push({nx, ny});
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> atlantic, ocean;
        for (int i = 0; i < n; i++)
        {
            atlantic.push({i, 0});
            visited[i][0] |= 1;
            ocean.push({i, m - 1});
            visited[i][m - 1] |= 2;
        }
        for (int i = 0; i < m; i++)
        {
            visited[0][i] |= 1;
            visited[n - 1][i] |= 2;
            atlantic.push({0, i});
            ocean.push({n - 1, i});
        }
        bfs(heights, 1, visited, atlantic, n, m);
        bfs(heights, 2, visited, ocean, n, m);
        vector<vector<int>> result;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 3)
                {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};