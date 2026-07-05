class Solution
{
public:
    string originalDigits(string s)
    {
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        vector<int> out(10, 0);
        out[0] = cnt['z' - 'a']; // zero
        out[2] = cnt['w' - 'a']; // two
        out[4] = cnt['u' - 'a']; // four
        out[6] = cnt['x' - 'a']; // six
        out[8] = cnt['g' - 'a']; // eight

        out[1] = cnt['o' - 'a'] - out[0] - out[2] - out[4]; // one
        out[3] = cnt['h' - 'a'] - out[8];                   // three
        out[5] = cnt['f' - 'a'] - out[4];                   // five
        out[7] = cnt['s' - 'a'] - out[6];                   // seven
        out[9] = cnt['i' - 'a'] - out[5] - out[6] - out[8]; // nine

        string ans;
        for (int d = 0; d <= 9; d++)
        {
            ans.append(out[d], '0' + d);
        }
        return ans;
    }
};
