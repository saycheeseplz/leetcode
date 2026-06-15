class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        st.push(0); // tầng gốc

        for (char c : s)
        {
            if (c == '(')
            {
                st.push(0); // mở tầng mới
            }
            else
            {
                int v = st.top();
                st.pop();
                int score = (v == 0 ? 1 : 2 * v);
                st.top() += score; // cộng vào tầng cha
            }
        }

        return st.top(); // điểm tổng
    }
};
