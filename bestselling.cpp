class Solution
{
public:
    pair<int, int> split(string s, bool &isEnd)
    {
        int n = s.size();
        int firstColon = s.find(':');
        int secondColon = s.find(':', firstColon + 1);

        int id = stoi(s.substr(0, firstColon));
        string type = s.substr(firstColon + 1, secondColon - firstColon - 1);
        int time = stoi(s.substr(secondColon + 1));

        isEnd = (type == "end");
        return {id, time};
    }

    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> result(n, 0);
        stack<int> st; // lưu ID hàm đang chạy
        int prevTime = 0;

        for (string s : logs)
        {
            bool isEnd;
            auto [id, time] = split(s, isEnd);

            if (!isEnd) // start
            {
                if (!st.empty())
                {
                    // cộng thời gian cho hàm hiện tại trước khi bị tạm dừng
                    result[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time; // cập nhật lại thời điểm bắt đầu
            }
            else // end
            {
                result[st.top()] += time - prevTime + 1; // +1 vì end tính cả timestamp hiện tại
                st.pop();
                prevTime = time + 1; // cập nhật cho hàm cha
            }
        }

        return result;
    }
};
