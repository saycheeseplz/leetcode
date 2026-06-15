#include <vector>
using namespace std;

class Solution
{
public:
    int nextIndex(vector<int> &nums, int i)
    {
        int n = nums.size();
        // công thức chuẩn để đưa về [0, n-1]
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                continue; // đã duyệt hoặc dead-end

            int slow = i, fast = i;
            bool forward = nums[i] > 0; // hướng di chuyển

            while (true)
            {
                // di chuyển slow 1 bước
                int nextSlow = nextIndex(nums, slow);
                if ((nums[nextSlow] > 0) != forward || nums[slow] == 0)
                    break;

                // di chuyển fast 1 bước
                int nextFast = nextIndex(nums, fast);
                if ((nums[nextFast] > 0) != forward || nums[fast] == 0)
                    break;

                // di chuyển fast thêm 1 bước nữa
                int nextFast2 = nextIndex(nums, nextFast);
                if ((nums[nextFast2] > 0) != forward || nums[nextFast] == 0)
                    break;

                slow = nextSlow;
                fast = nextFast2;

                if (slow == fast)
                {
                    if (slow == nextIndex(nums, slow))
                        break;   // cycle 1 phần tử -> không hợp lệ
                    return true; // tìm thấy cycle hợp lệ
                }
            }

            // không có cycle -> xoá dấu vết trên đường đi
            int j = i;
            while ((nums[j] > 0) == forward && nums[j] != 0)
            {
                int next = nextIndex(nums, j);
                nums[j] = 0; // đánh dấu dead-end
                j = next;
            }
        }
        return false;
    }
};
