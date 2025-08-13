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
void Ugly(vector<int> &arr, int n)
{
    int a = 1;
    int b = 1;
    int c = 1;
    while (arr.size() <= n)
    {
        for (int i = a; i * 2 <= b * 3 && i * 2 <= c * 5; i++)
        {
            if (arr[arr.size() - 1] == i * 2)
            {
                continue;
            }
            arr.push_back(i * 2);
            a = i + 1;
        }
        for (int i = b; b * 3 <= (a) * 2 && b * 3 <= c * 5; i++)
        {
            if (arr[arr.size() - 1] == i * 3)
            {
                continue;
            }
            arr.push_back(i * 3);
            b = i + 1;
        }
        for (int i = c; c * 5 < (a) * 2 && c * 5 < 3 * (b);)
        {
            arr.push_back(c * 5);
            c *= 5;
        }
    }
}
vector<int> a;

int nthUglyNumber(int n)
{
    a.push_back(1);
    Ugly(a, n);

    return a[n - 1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << nthUglyNumber(15);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}