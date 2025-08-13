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
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int c1 = 0;
    int c2 = matrix[0].size() - 1;
    int r1 = 0;
    int r2 = matrix.size() - 1;
    int l = c1;
    int r = c2;
    while (c1 <= c2 && r1 <= r2)
    {

        int mid = l + (r - l) / 2;
        if (matrix[r1][mid] == target)
        {
            return true;
        }
        if (matrix[r1][mid] > target)
        {
            c2 = mid - 1;
            r = c2;
        }
        else if (matrix[r1][mid] < target)
        {
            l = mid + 1;
        }

        if (l > r || r > c2)
        {
            l = c1;
            r = c2;
            r1++;
            continue;
        }
        if (matrix[r1][c2] < target)
        {
            r1++;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> matrix = {
        {5}, {6}
        // {1, 4, 7, 11, 15},
        // {2, 5, 8, 12, 19},
        // {3, 6, 9, 16, 22},
        // {10, 13, 14, 17, 24},
        // {18, 21, 23, 26, 30}
    };
    cout << searchMatrix(matrix, 6);
    return 0;
}