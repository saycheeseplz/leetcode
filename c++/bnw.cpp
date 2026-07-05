class Solution
{
public:
    string decodeAtIndex(string s, long long k)
    {
        long double size = 0;

        // forward compute full size
        for (char c : s)
        {
            if (isdigit(c))
                size *= (c - '0');
            else
                size += 1;
        }

        // backward find k-th char
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];

            if (isdigit(c))
            {
                int d = c - '0';
                size /= d;
                k = (long long)((long double)fmod(k, size));
                if (k == 0)
                    k = (long long)size;
            }
            else
            {
                if (k == (long long)size)
                    return string(1, c);
                size -= 1;
            }
        }

        return "";
    }
};
