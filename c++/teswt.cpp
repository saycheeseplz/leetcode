class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int l = 0;
        int count = 0;
        if (k != 0)
        {
            if (k != 0)
            {
                for (int i = 1; i < n; i++)
                {
                    if (i != n - 1 && nums[i] == nums[i + 1])
                    {
                        continue;
                    }
                    while ((l != n - 1 && nums[l] == nums[l + 1]) || (l < i && nums[i] - nums[l] > k))
                    {
                        l++;
                    }
                    if (nums[i] - nums[l] == k)
                    {
                        count++;
                    }
                }
                return count;
            }
            else
            {
                for (int i = 0; i < n - 1; i++)
                {
                    if (a[i] == a[i + 1])
                    {
                        count++;
                        int j = i;
                        while (j < n - 1 && a[j] == a[j + 1])
                        {
                            j++;
                        }
                        if (j == n - 1)
                        {
                            return count;
                        }
                        i = j - 1;
                    }
                }
            }
        }
        return count;
    }
};