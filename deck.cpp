class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = -1; // để xử lý trường hợp tổng chia hết cho k từ đầu
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            // Nếu k != 0 thì chỉ cần quan tâm phần dư
            int mod = (k == 0) ? sum : sum % k;

            // Đảm bảo mod không âm (C++ có thể cho ra âm nếu k âm)
            if (mod < 0)
                mod += k;

            // Nếu mod đã xuất hiện, kiểm tra xem có ít nhất 2 phần tử không
            if (mp.find(mod) != mp.end())
            {
                if (i - mp[mod] >= 2)
                    return true;
            }
            else
            {
                // Chỉ lưu vị trí đầu tiên mod xuất hiện (để có đoạn dài nhất)
                mp[mod] = i;
            }
        }
        return false;
    }
};
