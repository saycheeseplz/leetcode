#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int row, col;
    int total;
    unordered_map<int, int> swapped; // ánh xạ hoán đổi vị trí

public:
    Solution(int m, int n)
    {
        row = m;
        col = n;
        total = m * n;
    }

    vector<int> flip()
    {
        // chọn ngẫu nhiên 1 vị trí còn lại
        int r = rand() % total;
        total--;

        // nếu vị trí r đã được hoán đổi trước đó, dùng giá trị hoán đổi
        int index = swapped.count(r) ? swapped[r] : r;

        // ánh xạ r -> total (hoán đổi logic)
        swapped[r] = swapped.count(total) ? swapped[total] : total;

        // chuyển sang tọa độ 2D
        int i = index / col;
        int j = index % col;
        return {i, j};
    }

    void reset()
    {
        total = row * col;
        swapped.clear();
    }
};
