class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] != 0)
            {
                continue;
            }
            queue<int> q;

            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int x = q.front();
                q.pop();

                for (int point : graph[x])
                {
                    if (visited[point] == 0)
                    {
                        visited[point] = visited[x] == 1 ? 2 : 1;
                        q.push(point);
                    }
                    else if (visited[point] == visited[x])
                    {

                        return false;
                    }
                }
            }
        }
        return true;
    }
};