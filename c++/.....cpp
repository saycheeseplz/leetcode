class Solution
{
private:
    int n;
    vector<int> start;

public:
    Solution(vector<int> &w)
    {
        this->n = w.size();
        this->start = w;
    }

    int pickIndex()
    {
        int index = rand() % n;
        return start[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */