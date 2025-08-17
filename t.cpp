class Solution
{
public:
    int lengthLongestPath(string input)
    {
        unordered_map<int, int> depth_len; // depth -> total length up to that depth
        depth_len[0] = 0;
        int max_len = 0;

        stringstream ss(input);
        string line;
        while (getline(ss, line, '\n'))
        {
            int depth = 0;
            while (line[depth] == '\t')
                depth++; // đếm \t

            string name = line.substr(depth);
            if (name.find('.') != string::npos)
            {
                // là file -> update max_len
                max_len = max(max_len, depth_len[depth] + (int)name.size());
            }
            else
            {
                // là folder -> lưu độ dài để sau dùng
                depth_len[depth + 1] = depth_len[depth] + name.size() + 1; // +1 cho '/'
            }
        }

        return max_len;
    }
};
