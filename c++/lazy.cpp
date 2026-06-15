class Solution
{
public:
    int point(vector<pair<int, int>> start, int l, int r, int target)
    {
        while (l < r)
        {
            int m = (l + r) / 2;
            if (target == start[m].first)
            {
                return start[m].second;
            }
            else if (target < start[m].first)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
    vector<int> findRightInterval(vector<vector<int>> &intervals)

    {
        vector<pair<int, int>> start;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            start.push_back({intervals[i][0], i});
        }
        sort(start.begin(), start.end());
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (intervals[i][1] > start[n - 1].first)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(point(start, 0, n - 1, intervals[i][1]));
            }
        }
        return result;
    }
};