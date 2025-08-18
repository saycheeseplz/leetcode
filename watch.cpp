class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.size();
        int res = 0;
        for (int character = 1; character <= 26; character++)
        {
            vector<int> fre(26, 0);
            int distinct = 0;
            int list_characterWindow = 0;
            int l = 0;
            int r = 0;
            while (r < n)
            {
                if (fre[s[r] - 'a'] == 0)
                {
                    distinct++;
                    fre[s[r] - 'a']++;
                }
                if (fre[s[r] - 'a'] == k)
                {
                    list_characterWindow++;
                }
                r++;
                while (distinct > character)
                {
                    if (fre[s[l] - 'a'] == k)
                    {
                        list_characterWindow--;
                    }
                    fre[s[l] - 'a']--;
                    if (fre[s[l] - 'a'] == 0)
                    {
                        distinct--;
                    }
                    l++;
                }
                if (distinct == list_characterWindow && character == distinct)
                {
                    res = max(res, r - l + 1);
                }
            }
        }
        return res;
    }
};