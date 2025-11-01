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
    int val(string &s, int &i, int depth)
    {
        int count = 0;
        for (i; i < s.size(); i++)
        {
            if (s[i] == '(' && s[i + 1] == '(')
            {
                i++;
                count += 2 * val(s, i, depth + 1);
            }
            else if (s[i] == '(' && s[i + 1] == ')')
            {
                count += 1;
                i++;
            }
            else
            {

                return count;
            }
        }
        return count;
    }
    int scoreOfParentheses(string s)
    {
        int i = 0;
        return val(s, i, 0);
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution b;
    cout << b.scoreOfParentheses("(())()");

    return 0;
}