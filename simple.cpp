#include <iostream>
#include <vector>

int main()
{
    // Sửa lỗi cú pháp
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}}; // Thêm dấu ; ở đây

    std::vector<int> simple_vec = {10, 20, 30};

    // Đặt breakpoint ở dòng này
    std::cout << "Debug point - check variables!" << std::endl;

    return 0;
}