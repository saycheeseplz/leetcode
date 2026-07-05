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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 10;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += i;
    }
    cout << sum;
    return 0;
}