class Solution
{
public:
    int getSum(int a, int b)
    {
        int count = 0;
        int sum = 0;
        while (a == 0 && b == 0)
        {
            int n_a = (a & 1);
            int n_b = (b & 1);
            a >>= 1;
            b >>= 1;
            int x = n_a ^ n_b ^ 1;
            count = n_a == n_b == 1 || n_a == count == 1 || n_b == count == 1 ? 1 : 0;
            sum |= x;
            sum << 1;
        }
        return sum;
    }
};