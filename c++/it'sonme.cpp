class Solution
{
public:
    static bool cmd(string a, string b)
    {
        return a.size() > b.size();
    }
    bool choice(string a, string b, int len)
    {
        for (int i = 0; i < len; i++)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            if (a[i] < b[i])
            {
                return false;
            }
            return true;
        }
    }
    string findLongestWord(string s, vector<string> &dictionary)
    {
        int n = dictionary.size();
        if (s.empty() || dictionary.empty())
        {
            return "";
        }
        sort(dictionary.begin(), dictionary.end(), cmd);
        int index = -1;
        int len = 0;
        vector<int> word(n, -1);
        for (char c : s)
        {
            for (int i = 0; i < n; i++)
            {
                int n = dictionary[i].size();
                if (len > n)
                {
                    break;
                }
                int x = word[i] + 1;
                if (dictionary[i][x] == c)
                {
                    word[i]++;
                }
                if (word[i] == n - 1)
                {
                    if (len == n && choice(dictionary[i], dictionary[index], len))
                    {
                        continue;
                    }
                    index = i;
                    len = n;
                }
            }
        }
        return len == 0 ? "" : dictionary[index];
    }
};