int foldShift(long long key, int addressSize)
{
    string s = to_string(key);
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; i += addressSize)
    {
        sum += stoll(s.substr(i, addressSize));
    }
    return sum;
}

int rotation(long long key, int addressSize)
{
    string s = to_string(key);
    int n = s.size();
    string s = s.back() + s.substr(0, n - 1);
    foldShift(key, addressSize);
}