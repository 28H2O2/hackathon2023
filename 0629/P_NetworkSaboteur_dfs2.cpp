// P
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int N = 25;
int a[N + 1][N + 1];
bool vis[N] = {0};

int ans = 0;
int n = 0;

void dfs(int level, int sum)
{
    if (level == n)
    {
        return;
    }
    if (sum > ans)
    {
        ans = sum;
    }
    int record = sum;
    vis[level] = 1;
    for (int i = 0; i < n; ++i)
    {
        if (vis[i] == 0)
        {
            sum += a[level][i];
        }
        else
        {
            sum -= a[level][i];
        }
    }
    dfs(level + 1, sum);
    vis[level] = 0;
    dfs(level + 1, record);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(0, 0);
    cout << ans << endl;
}