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
string getHint(string secret, string guess)
{
    int pull = 0;
    int cow = 0;
    int a[10] = {0};
    for (int i = 0; i < secret.size(); i++)
    {
        a[secret[i] - '0']++;
        if (secret[i] == guess[i])
        {
            pull++;
        }
    }
    for (int i = 0; i < guess.size(); i++)
    {
        if (a[guess[i] - '0'] > 0)
        {
            cow++;
            a[guess[i] - '0']--;
        }
    }
    string s = to_string(pull) + "A" + to_string(cow) + "B";
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << getHint("1807", "7810");
    return 0;
}