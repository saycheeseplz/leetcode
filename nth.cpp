class Solution
{
public:
    int backtrack(int n, int len, int div, int &mod)
    {
        if (n > div * len)
        {
            return div + backtrack(n - div * len, len + 1, div * 10, mod);
        }
        else
        {
            mod = (n + 1) % len;
            return (n + 1) / len;
        }
    }
    int findNthDigit(int n)
    {

        int mod = 0;
        int num = backtrack(n, 1, 9, mod);
        string s = to_string(num);
        return s[mod] - '0';
    }
};