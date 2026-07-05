
void sortByFrequency(int arr[], int n)
{

    int mp_frequent[1000] for (int i = 0; i < n; i++)
    {
        if (mp_frequent[arr[i]] == 0)
        {
            mp_position[arr[i]] = i;
        }
        mp_frequent[arr[i]]++;
    }
    sort(arr, arr + n, [](int a, int b) -> bool
         {
             if (mp_frequent[a] == mp_frequent[b])
             {
                 return mp_position[a] < mp_position[b];
             }
             return mp_frequent[a] > mp_frequent[b]; });
}