
/*
Author : @wuan
Link :
*/
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        // Bước 1: Gặp nhau trong chu kỳ
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Bước 2: Tìm điểm bắt đầu chu kỳ (chính là số bị lặp)
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
    string s = to_string(pull) + "A" + to_string(cow) + "B";
    return s;
} int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << getHint("1807", "7810");
    return 0;
}
}
;
