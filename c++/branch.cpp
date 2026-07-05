class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        int m = s.size();
        vector<vector<int>> nxt(m + 1, vector<int>(26, -1));

        for (int i = m - 1; i >= 0; --i)
        {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i + 1;
        }

        string best = "";
        for (auto &w : dictionary)
        {
            int pos = 0;
            bool ok = true;
            for (char c : w)
            {
                pos = nxt[pos][c - 'a'];
                if (pos == -1)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                if (w.size() > best.size() ||
                    (w.size() == best.size() && w < best))
                    best = w;
            }
        }
        return best;
    }
};
