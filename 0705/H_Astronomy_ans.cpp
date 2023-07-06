/*
   本题属于圆周追击问题：
     假设已知两个圆周运动的物体的周期分别是a ,b, 设每隔时间t就会在同一条直线上
     在同一条直线上的条件是 角度之差为 PI !
     那么就有方程 （2PI/a - 2PI/b）* t=PI  所以就有 t=ab/(2|a-b|);
     如果有多个物体， 就会有多个t值，所以每隔 所有 t值的最小公倍数的时间所有的物体就会在同一直线上！

     另外：如果分数的分子分别是 a1, a2, ...., 和 b1, b2, ....
     那么所有分数的最小公倍数就是lcm(a1, a2, ...)/gcd(b1, b2,....);

     再有：如何求多个数的最小公倍数呢？
     根据数论，每一个数都可以表示成素数的乘积的形式！
     令p[i]存储素数，将a1,a2,...分别整除以p[i]，直到除尽！并记录除以每个p[i]时的个数temp;
     并更新该个数的最大值cnt[i]=max(temp, cnt[i]);

     最后cnt[i]个p[i]分别相乘得到最终的结果就是所有数的最小公倍数！
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#define M 10005
#define N 1005
using namespace std;
typedef long long LL;
LL p[M];
bool isP[M];
LL cnt[M];
LL q[N];
LL ans[N], endx;
LL top;

void bigN()
{ // 大数据的处理
    LL c = 0;
    endx = 0;
    ans[0] = 1;
    for (LL i = 0; i < top; ++i)
        for (LL j = 0; j < cnt[i]; ++j)
        {
            for (LL k = 0; k <= endx; ++k)
            {
                ans[k] = ans[k] * p[i] + c;
                c = ans[k] / 10000;
                ans[k] %= 10000;
            }
            if (c > 0)
            {
                ans[++endx] = c;
                c = 0;
            }
        }
}

void isPrime()
{
    LL i, j;
    isP[1] = 1;
    for (i = 2; i < M; ++i)
    {
        if (!isP[i])
            p[top++] = i;
        for (j = 0; j < top && i * p[j] < M; ++j)
        {
            isP[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}

void solve(LL k)
{
    for (LL i = 0; i < top && p[i] <= k; ++i)
    {
        LL tmp = 0;
        while (k % p[i] == 0)
        {
            ++tmp;
            k /= p[i];
        }

        if (tmp > cnt[i])
            cnt[i] = tmp;
    }
}

LL gcd(LL a, LL b)
{
    while (b)
    {
        LL r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    LL n;
    isPrime();
    while (scanf("%lld", &n) != EOF)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%lld", &q[0]);
        for (LL i = 1; i < n; ++i)
        {
            scanf("%lld", &q[i]);
            LL tmp = q[0] - q[i] > 0 ? q[0] - q[i] : q[i] - q[0];
            if (tmp != 0)
            {
                LL GCD = gcd(tmp, q[0] * q[i]);
                solve(q[0] * q[i] / GCD);
                q[i] = tmp / GCD;
            }
            else
                q[i] = 0;
        }

        LL ans2 = 0;
        for (LL i = 1; i < n; ++i)
            ans2 = gcd(ans2, q[i]);
        if (cnt[0] > 0) // 除以2
            --cnt[0];
        else
            ans2 *= 2;

        bigN();
        if (ans2 == 0)
        {
            endx = 0;
            ans[endx] = 0;
        }
        printf("%lld", ans[endx]);
        for (int i = endx - 1; i >= 0; --i)
            printf("%04lld", ans[i]);
        printf(" %lld\n", ans2);
    }
    return 0;
}