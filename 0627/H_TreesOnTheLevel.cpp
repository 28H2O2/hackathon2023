// H Accepted
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

struct Node
{
    int value;
    std::string direction;
};

bool operator>(const std::string &lhs, const std::string &rhs)
{
    if (lhs.length() > rhs.length())
    {
        return true;
    }
    else if (lhs.length() < rhs.length())
    {
        return false;
    }
    else
    {
        return lhs.compare(rhs) > 0;
    }
}

int findSameString(vector<string> check_string, string str)
{
    int num = 0;
    for (int i = 0; i < check_string.size(); ++i)
    {
        if (check_string[i] == str)
        {
            num++;
        }
    }
    return num;
}

string getMaxTruePrefix(string &str)
{
    if (str.length() <= 1)
    {
        return "";
    }
    else
    {
        return str.substr(0, str.length() - 1);
    }
}

int checkMaxTruePrefix(vector<string> check_string, string &str)
{
    string prefix = getMaxTruePrefix(str);
    return findSameString(check_string, str);
}

bool check_valid(vector<string> check_string)
{
    for (int i = 0; i < check_string.size(); ++i)
    {
        if (findSameString(check_string, check_string[i]) != 1)
        {
            return false;
        }
        if (checkMaxTruePrefix(check_string, check_string[i]) < 0)
        {
            return false;
        }
    }
    return true;
}

int partition(vector<Node> &tree, int front, int end)
{
    string x = tree[end].direction;
    int i = front - 1;
    for (int j = front; j <= end - 1; ++j)
    {
        if (x > tree[j].direction)
        {
            i++;
            Node temp;
            temp.direction = tree[j].direction;
            temp.value = tree[j].value;
            tree[j].direction = tree[i].direction;
            tree[j].value = tree[i].value;
            tree[i].direction = temp.direction;
            tree[i].value = temp.value;
        }
    }
    Node temp;
    temp.direction = tree[i + 1].direction;
    temp.value = tree[i + 1].value;
    tree[i + 1].direction = tree[end].direction;
    tree[i + 1].value = tree[end].value;
    tree[end].direction = temp.direction;
    tree[end].value = temp.value;
    return i + 1;
}

void quick_sort(vector<Node> &tree, int front, int end)
{
    if (front < end)
    {
        int q = partition(tree, front, end);
        quick_sort(tree, front, q - 1);
        quick_sort(tree, q + 1, end);
    }
}

int main()
{
    std::vector<std::vector<Node>> trees;
    std::vector<Node> currentTree;

    std::string line;
    while (std::getline(std::cin, line))
    { // 读取每一行
        if (cin.eof())
        {
            // 读取到 EOF，跳出循环
            break;
        }
        std::istringstream iss(line);
        std::string token;
        while (std::getline(iss, token, ' '))
        { // 使用空格作为分隔符
            if (token == "()")
            { // 检测到空的括号，表示树的结束
                if (!currentTree.empty())
                {
                    trees.push_back(currentTree); // 将当前树添加到trees中
                    currentTree.clear();          // 清空当前树的节点
                }
            }
            else
            {
                size_t pos = token.find(","); // 找到逗号的位置
                if (pos != std::string::npos)
                {
                    std::string value_str = token.substr(1, pos - 1);
                    std::string direction = token.substr(pos + 1, token.size() - pos - 2);

                    Node node;
                    node.value = std::stoi(value_str); // 将字符串转换为整数
                    node.direction = direction;

                    currentTree.push_back(node); // 将node添加到当前树中
                }
            }
        }
    }
    // cout << "1" << endl;
    int flag = true;
    //* 处理数据
    for (auto &tree : trees)
    {
        quick_sort(tree, 0, tree.size() - 1);

        // for (int i = tree.size() - 1; i >= 0; --i)
        // {
        //     string truePrefix = getMaxTruePrefix(tree[i].direction);
        // }
    }

    // 输出读取到的数据
    for (const auto &tree : trees)
    {
        if (tree[0].direction != "")
        {
            cout << "not complete" << endl;
            continue;
        }
        vector<string> check_string(tree.size());
        for (int i = 0; i < tree.size(); ++i)
        {
            check_string[i] = tree[i].direction;
        }
        if (check_valid(check_string) == false)
        {
            cout << "not complete" << endl;
            continue;
        }
        int count = 0;
        for (const auto &node : tree)
        {
            count++;
            // std::cout << "  Value: " << node.value << ", Direction: " << node.direction << std::endl;
            if (count == 1)
                cout << node.value;
            else
                cout << " " << node.value;
        }
        cout << endl;
    }
    // cout << endl;
    return 0;
}
