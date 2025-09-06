class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1); // Khởi tạo kết quả là -1
        stack<int> st;          // Lưu chỉ số của các phần tử chưa tìm được next greater

        for (int i = 0; i < 2 * n; ++i)
        {                    // Duyệt 2 vòng để mô phỏng circular
            int idx = i % n; // Chỉ số trong mảng gốc
            while (!st.empty() && nums[st.top()] < nums[idx])
            {
                res[st.top()] = nums[idx]; // Gán next greater
                st.pop();
            }
            if (i < n)
                st.push(i); // Chỉ push vòng đầu tiên
        }

        return res;
    }
};