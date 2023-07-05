// J Accepted
// 感觉是一个字符串匹配 用KMP试试？
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

void prefix_init(vector<int> &prefix, char *input, int length)
{
    prefix[0] = -1;
    int k = -1;
    for (int i = 1; i < length; ++i)
    {
        while (input[k + 1] != input[i] && k > -1)
        {
            k = prefix[k];
        }
        if (input[k + 1] == input[i])
        {
            k++;
        }
        prefix[i] = k;
    }
}

int cal_kmp_matcher(vector<int> &prefix, char *input, int input_length, char *matcher, int matcher_length)
{
    int sum = 0;
    int k = -1;
    for (int i = 0; i < input_length; ++i)
    {
        while (k > -1 && matcher[k + 1] != input[i])
        {
            k = prefix[k];
        }
        if (matcher[k + 1] == input[i])
        {
            k++;
        }
        if (k == matcher_length - 1)
        {
            sum++;
            // !这里两行很关键，Wrong Answer和TLE的错误都在这里
            // i = i - matcher_length + 1;
            // k = -1;
            k = prefix[k];
        }
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    const int W_size = 10005;
    const int T_size = 1000005;
    char a[W_size];
    char b[T_size];
    vector<int> prefix(W_size);
    for (int i = 0; i < n; ++i)
    {
        cin.getline(a, W_size);
        cin.getline(b, T_size);
        // int prefix[strlen(a)];
        prefix_init(prefix, a, strlen(a));
        int sum = cal_kmp_matcher(prefix, b, strlen(b), a, strlen(a));
        cout << sum << endl;
        prefix.clear();
    }
}
