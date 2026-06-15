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

#include <bits/stdc++.h>
using namespace std;

class Twitter
{
private:
    unordered_map<int, unordered_set<int>> tweet;    // user -> followees
    unordered_map<int, vector<pair<int, int>>> post; // user -> list of {tweetId, time}
    int timeline = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        post[userId].push_back({tweetId, timeline++});
    }

    vector<int> getNewsFeed(int userId)
    {
        tweet[userId].insert(userId); // tự follow chính mình
        vector<int> result;
        priority_queue<array<int, 3>> qe;

        for (auto account : tweet[userId])
        {
            auto &acc = post[account];
            if (!acc.empty())
            {
                int n = acc.size() - 1;
                qe.push({acc[n].second, acc[n].first, account * 100000 + n});
            }
        }

        while (!qe.empty() && result.size() < 10)
        {
            auto top = qe.top();
            qe.pop();

            int time = top[0];
            int id = top[1];
            int person = top[2];

            int account = person / 100000;
            int idx = person % 100000;

            result.push_back(id);

            if (idx > 0)
            {
                int newIdx = idx - 1;
                qe.push({post[account][newIdx].second, post[account][newIdx].first, account * 100000 + newIdx});
            }
        }
        return result;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            tweet[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        tweet[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}