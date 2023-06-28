// J
// 感觉是一个字符串匹配 用KMP试试？
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

void prefix_init(int *prefix, char *input, int length)
{
    prefix[0] = -1;
    int k = -1;
    for (int i = 1; i < length; ++i)
    {
        while (input[k + 1] != input[i] && k > -1)
        {
            k = prefix[k];
        }
    }
}

int kmp(char[])
{
}

int main()
{
    int n;
    cin >> n;
    getchar();
    const int W_size = 10000;
    const int T_size = 1000000;
    char a[W_size];
    char b[T_size];
    for (int i = 0; i < n; ++i)
    {
        cin.getline(a, W_size);
        cin.getline(b, T_size);
        int prefix[W_size];
        prefix_init(prefix, a, W_size);
    }
}
