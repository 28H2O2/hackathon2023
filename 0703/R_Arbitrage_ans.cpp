#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;            // n种货币，m条兑换
map<string, int> mp; // 为每种货币编号
double d[100][100];  // 用来储存 i -> j 的总汇率，即：将每条兑换的汇率相乘所得积
int cnt = 1;         // 用以计数 Case的序号

char a[35];
char from[35], to[35]; // 为避免string必须用cin而有可能导致超时的情况，全部使用char数组
double val;            // 当前汇率,没必要全部存下来，反正都存在d[][]里面了

void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][j] < d[i][k] * d[k][j])
                    // 如果当前 i -> j的总汇率比新的低，则替换
                    // 汇率高意味着一个单位的货币能兑换更多
                    d[i][j] = d[i][k] * d[k][j];
    // floyd标准算法框架，注意本题是汇率，所以相乘而不是相加

    for (int i = 0; i < n; i++) // 将所有货币遍历一遍
        if (d[i][i] > 1.0)
        { // 如果有货币在更新了后本身兑换本身的汇率大于 1.0，则能够套利
            printf("Case %d: Yes\n", cnt++);
            return;
        }

    printf("Case %d: No\n", cnt++);
    return;
}

int main()
{
    while (~scanf("%d", &n), n)
    {
        memset(d, 0, sizeof(d)); // 处理每组样例时将d[][]初始化

        for (int i = 0; i < n; i++)
        {
            scanf("%s", a);
            mp[a] = i; // 为货币编号
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%s%lf%s", from, &val, to);
            // 字符串用 s, double类型用 lf
            // char数组的名字是一个指针，所以不用加 &
            // 即对char a[] : &a[0] = a
            d[mp[from]][mp[to]] = val; // 保存各货币间的汇率
        }
        floyd(); // 处理
    }

    return 0;
}