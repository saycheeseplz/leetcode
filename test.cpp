<<<<<<< HEAD
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        // Bước 1: Gặp nhau trong chu kỳ
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Bước 2: Tìm điểm bắt đầu chu kỳ (chính là số bị lặp)
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
=======
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
>>>>>>> memo
