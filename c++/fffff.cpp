vector<int> x{-1, 0, 0, 1};
vector<int> y{0, -1, 1, 0};
bool canEatFood(int maze[5][5], int fx, int fy)
{
    stack<pair<int, int>> st;
    st.push({0, 0});
    vector<vector<int>> visited(5, vector<int>(5, 0));
    while (!st.empty())
    {
        int n = st.size();
        for (int i = 0; i < n; i++)
        {
            int a = st.top().first;
            int b = st.top().second;
            visited[a][b] = 1;
            st.pop();
            for (int j = 0; j < 4; j++)
            {
                int na = a + x[j];
                int nb = b + y[j];
                if (na == fx && nb == fy)
                {
                    return true;
                }
                if (na >= 0 && nb >= 0 && na < 5 && nb < 5 && maze[na][nb] == 1)
                {
                    st.push({na, nb});
                }
            }
        }
    }
    return false;
}