// J
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int N = 100000;
const int M = 10;
int a[N][M] = {0};
int capacity[M] = {0};
int ans[M] = {0};

int main()
{
    int n, m;
    while (1)
    {

        int a[N][M] = {0};
        int capacity[M] = {0};
        int ans[M] = {0};
        cin >> n >> m;
        if (cin.eof())
        {
            // 读取到 EOF，跳出循环
            break;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> capacity[i];
        }
        bool ans = false;
        for (int i = 0; i < m; ++i)
        {
        }
        cin.ignore();
    }
}