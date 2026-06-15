#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> firstIndex;
        int diff = 0; // hiệu giữa số lượng 1 và 0
        int maxLen = 0;

        firstIndex[0] = -1; // hiệu = 0 trước khi duyệt

        for (int i = 0; i < (int)nums.size(); i++)
        {
            diff += (nums[i] == 1 ? 1 : -1);

            // nếu diff này đã gặp trước đó -> đoạn giữa 2 vị trí có số 0 và 1 bằng nhau
            if (firstIndex.count(diff))
            {
                maxLen = max(maxLen, i - firstIndex[diff]);
            }
            else
            {
                firstIndex[diff] = i; // lưu vị trí đầu tiên gặp diff
            }
        }

        return maxLen;
    }
};
