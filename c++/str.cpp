class Solution
{
public:
    int findSubstringInWraproundString(string s)
    {
        vector<int> maxLen(26, 0);
        int n = s.size();
        int k = 0; // độ dài substring liên tiếp wraparound hiện tại

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && (s[i] - s[i - 1] + 26) % 26 == 1)
            {
                k++;
            }
            else
            {
                k = 1;
            }
            int idx = s[i] - 'a';
            maxLen[idx] = max(maxLen[idx], k);
        }

        int result = 0;
        for (int x : maxLen)
            result += x;
        return result;
    }
};
