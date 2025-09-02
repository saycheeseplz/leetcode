class Solution
{
public:
    bool wise_choice(int n, int need, int bitMask, unordered_map<int, bool> &mp)
    {
        if (mp.count(bitMask))
            return mp[bitMask];

        for (int i = 1; i <= n; i++)
        {
            int bit = 1 << (i - 1);
            if ((bit & bitMask) == 0)
            { // chưa chọn i
                if (i >= need)
                    return mp[bitMask] = true; // thắng ngay
                if (!wise_choice(n, need - i, bitMask | bit, mp))
                    return mp[bitMask] = true; // chọn i → đối thủ thua
            }
        }
        return mp[bitMask] = false; // mọi lựa chọn đều để đối thủ thắng
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (desiredTotal <= 0)
            return true;
        if (sum < desiredTotal)
            return false;

        unordered_map<int, bool> mp;
        return wise_choice(maxChoosableInteger, desiredTotal, 0, mp);
    }
};
