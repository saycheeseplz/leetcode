class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> nge_map;
        stack<int> st;

        for (int num : nums2)
        {
            while (!st.empty() && num > st.top())
            {
                nge_map[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        while (!st.empty())
        {
            nge_map[st.top()] = -1;
            st.pop();
        }

        vector<int> result;
        for (int num : nums1)
        {
            result.push_back(nge_map[num]);
        }
        return result;
    }
};
