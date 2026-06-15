class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int res = 0;
        for (int house : houses)
        {
            // tìm vị trí lò sưởi gần nhất so với house bằng binary search
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            int dist1 = INT_MAX, dist2 = INT_MAX;

            if (it != heaters.end())
            {
                dist1 = abs(*it - house); // lò sưởi bên phải hoặc trùng
            }
            if (it != heaters.begin())
            {
                dist2 = abs(*(it - 1) - house); // lò sưởi bên trái
            }

            int nearest = min(dist1, dist2);
            res = max(res, nearest);
        }

        return res;
    }
};
