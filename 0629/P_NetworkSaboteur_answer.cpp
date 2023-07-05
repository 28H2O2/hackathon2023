#include <cstdio>
using namespace std;

const int N = 25;
int a[N][N];
bool vis[N] = {0}; // 对拿出的节点进行标记

int n, ans = 0;
void dfs(int m, int sum)
{
    if (m == n + 1)
    {
        return; // 访问到最后一行返回
    }

    if (sum > ans)
    {
        ans = sum; // 修改最大值
    }

    int t = sum; // 记录当前值，返回时使用
    vis[m] = 1;  // 标记被拿出的节点
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
        {
            sum -= a[m][i]; // 将被拿出的节点所对的减去
        }
        else
        {
            sum += a[m][i]; // 将未被拿出节点加上
        }
    }
    dfs(m + 1, sum); // 对下一行进行搜索
    vis[m] = 0;      // 返回后将标记删除
    dfs(m + 1, t);   // 继续搜索下一行
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    dfs(1, 0);

    printf("%d\n", ans);
    return 0;
}