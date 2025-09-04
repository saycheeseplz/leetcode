class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        unordered_set<int> se;
        int max_heat = heaters[0];
        int min_heat = heaters[0];
        for (int i = 0; i < heaters.size(); i++)
        {
            se.insert(heaters[i]);
        }
        int max_radius = 0;
        for (int i = 0; i < houses.size(); i++)
        {
        }
    }
};