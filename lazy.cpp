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
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(end))
            return -1;

        queue<pair<string, int>> q;
        q.push({start, 0});
        vector<char> choices = {'A', 'C', 'G', 'T'};

        while (!q.empty())
        {
            auto [gene, step] = q.front();
            q.pop();
            if (gene == end)
                return step;

            for (int i = 0; i < gene.size(); i++)
            {
                char old = gene[i];
                for (char c : choices)
                {
                    if (c == old)
                        continue;
                    gene[i] = c;
                    if (dict.count(gene))
                    {
                        q.push({gene, step + 1});
                        dict.erase(gene);
                    }
                }
                gene[i] = old;
            }
        }
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution b;
    vector<string> bank({"AACCGGTA", "AACCGCTA", "AAACGGTA"});
    cout << b.minMutation("AACCGGTT", "AAACGGTA", bank);

    return 0;
}