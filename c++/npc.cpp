class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> freq(26, 0); // đếm tần suất chữ cái
        int l = 0, maxFreq = 0, max_val = 0;

        for (int r = 0; r < s.size(); r++)
        {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // Nếu cửa sổ không hợp lệ (cần đổi > k ký tự), co cửa sổ lại
            while ((r - l + 1) - maxFreq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }

            max_val = max(max_val, r - l + 1);
        }
        return max_val;
    }
};
