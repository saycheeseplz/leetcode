class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        vector<int> lpf(n, 0);
        int len = 0;
        int i;
        for (i = 1; len = 0; i < n)
        {
            if (s[i] == s[len])
            {
                lps[i++] = ++len;
            }
            else if (len)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }
        int longest = lps[n - 1];
        return longest > 0 && n % (n - longest) == 0;
    }
};