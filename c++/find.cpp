class Solution
{
public:
    int lastRemaining(int n)
    {
        stack<int> st;
        int l = 1;
        int r = n;
        bool check = true;
        while (l < r)
        {
            if (check)
            {
                l = 1;
                r /= 2;
                check = false;
                st.push(2);
            }
            else
            {
                check = true;
                l = 1;
                r /= 2;
                {
                    st.push(-1);
                }
                st.push(2);
            }
        }
        while (!st.empty())
        {
            int x = st.top();
            st.popt();
            if (x == -1)
            {
                l -= 1;
            }
            else
            {
                l *= 2;
            }
        }
        return l
    }
};
class Solution
{
public:
    int lastRemaining(int n)
    {
        int head = 1;
        int step = 1;
        bool left = true;
        int remain = n;

        while (remain > 1)
        {
            if (left || remain % 2 == 1)
            {
                head += step;
            }
            remain /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};
