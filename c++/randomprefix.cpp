class Solution
{
public:
    vector<int> prefix;
    int total;

    Solution(vector<int> &w)
    {
        prefix.resize(w.size());
        prefix[0] = w[0];
        for (int i = 1; i < w.size(); i++)
        {
            prefix[i] = prefix[i - 1] + w[i];
        }
        total = prefix.back(); // tổng tất cả trọng số
    }

    int pickIndex()
    {
        int r = rand() % total + 1; // random từ 1 đến total
        int idx = lower_bound(prefix.begin(), prefix.end(), r) - prefix.begin();
        return idx;
    }
};
