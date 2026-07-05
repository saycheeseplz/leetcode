class tree
{
private:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

public:
    void add(string &s)
    {
        if (parent.count(s) == 0)
        {
            parent[s] = s;
            weight[s] = 1;
        }
    }
    pair<string, double> find(string &s)
    {
        if (parent[s] != s)
        {
            auto p = find(parent[s]);
            parent[s] = p.first;
            weight[s] *= p.second;
        }
        return {parent[s], weight[s]};
    }
    void connect(string &a, string &b, double val)
    {
        add(a);
        add(b);
        auto root_a = find(a);
        auto root_b = find(b);
        if (root_a.first != root_b.first)
        {
            parent[root_a.first] = root_b.first;
            weight[root_a.first] = val * root_b.second / root_a.second;
        }
    }
    double divide(string &a, string &b)
    {
        if (parent.count(a) == 0 || parent.count(b) == 0)
        {
            return -1;
        }
        auto root_a = find(a);
        auto root_b = find(b);
        if (root_a.first != root_b.first)
        {
            return -1;
        }
        return root_a.second / root_b.second;
    }
};
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        tree utf;
        for (int i = 0; i < equations.size(); i++)
        {
            utf.connect(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> results;
        for (auto que : queries)
        {
            results.push_back(utf.divide(que[0], que[1]));
        }
        return results;
    }
};