class Solution
{
public:
    int findLUSlength(vector<string> &strs)
    {
        unordered_map<string, int> mp;
        string i = "";
        for (string c : strs)
        {
            if (i.size() < c.size())
            {
                i = c;
            }
            mp[c]++;
        }
        if (mp[i] >= 2)
        {
            return -1;
        }
        return i.size();
    }
};