/*
Author : @wuan
Link :
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define endl '\n'

class Solution
{
public:
    pair<int, int> split(string s, bool &check)
    {
        int a = -1;
        int b = -1;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {

            if (s[i] == ':')
            {
                if (a == -1)
                {
                    if (s[i + 1] == 's')
                    {
                        check = false;
                    }
                    else
                    {
                        check = true;
                    }

                    a = stoi(s.substr(0, i));
                }
                else
                {
                    b = stoi(s.substr(i + 1));
                    return {a, b};
                }
            }
        }
        return {0, 0};
    }
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> time(n, 0);
        time.reserve(n);
        stack<pair<int, int>> st;
        int count = 0;
        for (string s : logs)
        {
            bool check = false;
            pair<int, int> temp = split(s, check);
            if (st.empty() || !check)
            {
                if (st.empty())
                {
                    count = 0;
                }

                st.push(temp);
            }
            else
            {
                time[temp.first] += temp.second - st.top().second - count + 1;
                count += time[temp.first];
                st.pop();
            }
        }
        return time;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution b;
    vector<string> logs({"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"});
    b.exclusiveTime(2, logs);

    return 0;
}