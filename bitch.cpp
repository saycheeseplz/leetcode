class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        int remaining = 0; // số continuation byte còn cần

        for (int num : data)
        {
            if (remaining == 0)
            {
                // Đếm số bit 1 liên tiếp từ trái
                int mask = 0b10000000;
                int count = 0;
                while (mask & num)
                {
                    count++;
                    mask >>= 1;
                }

                // Byte đầu hợp lệ: 0, 2, 3, 4 byte; 1 hoặc >4 là sai
                if (count == 1 || count > 4)
                    return false;

                remaining = count == 0 ? 0 : count - 1;
            }
            else
            {
                // Byte continuation phải bắt đầu bằng 10
                if ((num & 0b11000000) != 0b10000000)
                    return false;
                remaining--;
            }
        }

        // Sau khi duyệt hết, không còn continuation byte bị thiếu
        return remaining == 0;
    }
};
