class Solution
{
public:
    int num(int n, int m)
    {
        n %= 1337;
        int res = 1;
        while (m != 0)
        {
            if (m % 2 == 1)
            {
                res = ((res % 1337) * (n % 1337)) % 1337;
            }
            n = ((n % 1337) * (n % 1337)) % 1337;
            m /= 2;
        }
        return res;
    }
    int superPow(int a, vector<int> &b)
    {
        if (a == 1)
        {
            return 1;
        }
        int n = b.size();
        int count = num(a, b[0]);
        for (int i = 1; i < n; i++)
        {
            count = num(count, 10);
            int count_next = num(a, b[i]);
            count = (count * count_next) % 1337;
        }
        return count;
    }
};