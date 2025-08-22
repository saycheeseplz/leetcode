class Solution
{
public:
    vector<int> dx{-1, 1, 0, 0};
    vector<int> dy{0, 0, -1, 1};
    void dfs(vector<vector<int>> board, int x, int y, int n, int m)
    {
        board[x][y] = '_';
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'X')
            {
                dfs(board, nx, ny, n, m);
            }
        }
    }

    int countBattleships(vector<vector<char>> &board)
    {
        int count = 0;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'X')
                {
                    count++;
                    dfs(board, i, j, n, m);
                }
            }
        }
        return count;
    }
};