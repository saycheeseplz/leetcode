class Solution
{
public:
    vector<vector<int>> rects;
    vector<int> prefixSum; // tổng số điểm tới hình chữ nhật i
    int totalPoints;

    Solution(vector<vector<int>> &rects)
    {
        this->rects = rects;
        prefixSum.push_back(0);
        totalPoints = 0;
        for (auto &r : rects)
        {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            int area = (x2 - x1 + 1) * (y2 - y1 + 1); // số điểm trong hình chữ nhật
            totalPoints += area;
            prefixSum.push_back(totalPoints);
        }
    }

    vector<int> pick()
    {
        // Chọn số ngẫu nhiên từ 0 đến totalPoints - 1
        int randPoint = rand() % totalPoints;

        // Tìm hình chữ nhật chứa điểm này bằng binary search
        int l = 0, r = prefixSum.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (prefixSum[mid] <= randPoint)
                l = mid + 1;
            else
                r = mid;
        }
        int idx = l - 1; // hình chữ nhật chứa điểm

        vector<int> rct = rects[idx];
        int x1 = rct[0], y1 = rct[1], x2 = rct[2], y2 = rct[3];

        // Chọn điểm ngẫu nhiên trong hình chữ nhật đã chọn
        int lenX = x2 - x1 + 1;
        int lenY = y2 - y1 + 1;
        int localPoint = randPoint - prefixSum[idx]; // vị trí điểm trong hình chữ nhật
        int x = localPoint % lenX;
        int y = localPoint / lenX;
        return {x1 + x, y1 + y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
