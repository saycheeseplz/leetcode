class Solution
{
public:
    static bool cmd(pair<int, int> a, pair<int, int> b)
    {
        if (a.first >= b.first)
        {
            return true;
        }
        return false;
    }
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> flag;
        int n = position.size();
        for (int i = 0; i < n; i++)
        {
            flat.push_back({position[i], speed[i]});
        }
        sort(flat.begin(), flat.end(), cmd);
        stack<int> st;
        for (auto temp : flat)
        {
            int distance = temp.first;
            int sd = temp.second;
            int time = (target - distance) / sd;
            if (st.empty())
            {
                st.push(time);
            }
            else
            {
                if (st.top() < time)
                {
                    st.push(time);
                }
            }
        }
        return st.size();
    }
};