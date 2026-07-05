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

int maxNumberOfPeople(vector<int> &rooms, vector<int> &people, int k)
{
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());
    int count = 0;
    int idx = 0;
    for (int i = 0; i < rooms.size(); i++)
    {
        if (people[idx] - 5 > rooms[i])
        {
            continue;
        }
        if (people[idx] + 5 < rooms[i])
        {
            idx++;
            i--;
            continue;
        }
        count++;
        idx++;
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int peopleCount, roomCount, k;
    cin >> peopleCount >> roomCount >> k;

    vector<int> people(peopleCount);
    vector<int> rooms(roomCount);

    for (int i = 0; i < peopleCount; i++)
        cin >> people[i];
    for (int i = 0; i < roomCount; i++)
        cin >> rooms[i];
    cout << maxNumberOfPeople(rooms, people, k) << '\n';
    return 0;
}