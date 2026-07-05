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
    unordered_map<string, vector<int>> mp;
    vector<int> diffWaysToCompute(string expression)
    {
        if (!mp[expression].empty())
        {
            return mp[expression];
        }
        vector<int> result;
        for (int i = 0; i < expression.size(); i++)
        {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int num1 : left)
                {
                    for (int num2 : right)
                    {
                        if (c == '+')
                        {
                            result.push_back(num1 + num2);
                        }
                        else if (c == '-')
                        {
                            result.push_back(num1 - num2);
                        }
                        else
                        {
                            result.push_back(num1 * num2);
                        }
                    }
                }
                mp[expression] = result;
            }
        }
        if (result.empty())
        {
            result.push_back(stoi(expression));
        }
        return result;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution b;
    vector<int> a;
    a = b.diffWaysToCompute("2*3-4*5");
    return 0;
}