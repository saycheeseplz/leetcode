class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        deque<int> dq;
        for (int n - 1; i >= 0; i--)
        {
            if (!dq.empty())
            {
                dp.push_front(dp.back());
                dp.pop_back();
            }
            dp.push_front(deck[i]);
        }
        int x = 10;
        return vector<int>(dq.begin(), dq.end());
    };
    // fuck you babay pack packc