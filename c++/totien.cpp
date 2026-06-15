static void merge(T *start, T *middle, T *end)
{
    int n = middle - start;
    int m = end - middle;
    T *left = new T[n];
    T *right = new T[m];

    for (int i = 0; i < n; i++)
        left[i] = start[i];
    for (int i = 0; i < m; i++)
        right[i] = middle[i];

    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (left[i] <= right[j])
        {
            start[k++] = left[i++];
        }
        else
        {
            start[k++] = right[j++];
        }
    }

    while (i < n)
        start[k++] = left[i++];
    while (j < m)
        start[k++] = right[j++];

    delete[] left;
    delete[] right;
}
static void InsertionSort(T *start, T *end)
{
    int n = end - start;
    for (int i = 1; i < n; i++)
    {
        T key = start[i];
        int j = i - 1;
        while (j >= 0 && start[j] > key)
        {
            start[j + 1] = start[j];
            j--;
        }
        start[j + 1] = key;
    }
}

static void TimSort(T *start, T *end, int min_size)
{
    int n = end - start;
    if (n <= 1)
        return;

    // Bước 1: Sort các đoạn min_size
    for (int i = 0; i < n; i += min_size)
    {
        T *chunk_end = (i + min_size < n) ? (start + i + min_size) : end;
        InsertionSort(start + i, chunk_end);
    }

    cout << "Insertion Sort: ";
    printArray(start, end);

    // Bước 2: Iterative bottom-up merge
    int merge_count = 0;

    for (int size = min_size; size < n; size *= 2)
    {
        for (int left_start = 0; left_start < n; left_start += 2 * size)
        {
            int middle_idx = left_start + size;
            int right_idx = min(left_start + 2 * size, n);

            // Merge nếu có phần tử bên phải
            if (middle_idx < n)
            {
                merge(start + left_start, start + middle_idx, start + right_idx);
            }

            // In sau mỗi lần lặp (kể cả khi không merge)
            merge_count++;
            cout << "Merge " << merge_count << ": ";
            printArray(start, end);
        }
    }
}