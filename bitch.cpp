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
    string repeat(int n, string s)
    {
        string word = s;
        for (int i = 1; i < n; i++)
        {
            word += s;
        }
        return word;
    }
    string decodeString(string s)
    {
        string word = "";
        for (int i = 0; i < s.size(); i++)
        {
            string word1;
            int res = 1;
            if (isdigit(s[i]))
            {
                res = 0;
                while (isdigit(s[i]))
                {
                    res = res * 10 + (s[i] - '0');
                    i++;
                }
            }
            if (s[i] == '[')
            {
                int depth = 0;
                int j = i + 1;
                while (!(depth == 0 && s[j] == ']'))
                {
                    if (s[j] == '[')
                    {
                        depth++;
                    }
                    else if (s[j] == ']')
                    {
                        depth--;
                    }
                    j++;
                }
                word1 = decodeString(s.substr(i + 1, j - i - 1));
                i = j;
            }
            else
            {
                word1 += s[i];
            }
            word += repeat(res, word1);
        }
        return word;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution b;
    cout << b.decodeString("3[a]2[bc]");
    return 0;
}
// prenium
class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> counts;         // lưu số lần repeat
        stack<string> resultStack; // lưu chuỗi trước dấu [
        string current = "";
        int k = 0;

        for (char c : s)
        {
            if (isdigit(c))
            {
                k = k * 10 + (c - '0'); // tính số nhiều chữ số
            }
            else if (c == '[')
            {
                counts.push(k);
                resultStack.push(current);
                current = "";
                k = 0;
            }
            else if (c == ']')
            {
                int repeatTimes = counts.top();
                counts.pop();
                string prev = resultStack.top();
                resultStack.pop();

                // tối ưu nối string bằng reserve
                string repeated;
                repeated.reserve(current.size() * repeatTimes);
                for (int i = 0; i < repeatTimes; i++)
                    repeated += current;

                current = prev + repeated;
            }
            else
            {
                current += c; // ký tự bình thường
            }
        }

        return current;
    }
};
