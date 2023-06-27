#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 删除第三个元素
    vec.erase(vec.begin() + 2);

    // 输出剩余元素
    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}