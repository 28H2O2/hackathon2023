// H
// 求最小公倍数?
// 分数求最小公倍数 = 分子的最小公倍数/分母的最大公约数
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
// #include <map>
// #include <unordered_set>
#include <algorithm>
// #include <cmath>

using namespace std;

typedef struct
{
    long long m;
    long long n;
} fraction;

fraction multi(fraction x, fraction y)
{
    fraction ans;
    ans.m = x.m * y.m;
    ans.n = x.n * y.n;
    return ans;
}

fraction subtraction(fraction x, fraction y)
{
    fraction ans;
    ans.m = x.m * y.n - x.n * y.m;
    ans.n = x.n * y.n;
    return ans;
}

long long lcm(long long x, long long y)
{
    long long ans = x * y;
    while (x % y != 0)
    {
        long long temp = x % y;
        x = y;
        y = temp;
    }
    return ans / y;
}
long long gcd(long long x, long long y)
{
    long long ans;
    while (x % y != 0)
    {
        long long ans = x % y;
        x = y;
        y = ans;
    }
    return y;
}

fraction lcm_frac(fraction x, fraction y)
{
    fraction ans;
    ans.m = lcm(x.m, y.m);
    ans.n = gcd(x.n, y.n);
    return ans;
}

fraction reduction(fraction x)
{
    fraction ans;
    int temp = gcd(x.m, x.n);
    ans.m = x.m / temp;
    ans.n = x.n / temp;
    return ans;
}
int main()
{
    long long N;
    cin >> N;
    vector<long long> a(N);
    // vector<fraction> ans(N);
    vector<fraction> b(N);
    cin >> a[0];
    for (int i = 1; i < N; ++i)
    {
        cin >> a[i];
        if (a[i] - a[0] == 0)
        {
            b[i - 1] = {1, 1};
            continue;
        }
        long long temp = a[i] - a[0];
        temp = temp > 0 ? temp : (-temp);
        b[i - 1] = {a[i] * a[0], 2 * temp};
        b[i - 1] = reduction(b[i - 1]);
        // b[i].n = a[i];
        // b[i].m = 2;
    }
    for (int i = 0; i < N - 2; ++i)
    {
        // b[i + 1] = lcm_frac(b[i], b[i + 1]);
        b[i + 1].m = lcm(b[i + 1].m, b[i].m);
        b[i + 1].n = gcd(b[i + 1].n, b[i].n);
    }
    fraction ans = b[N - 2];
    b[N - 2] = reduction(b[N - 2]);
    cout << b[N - 2].m << " " << b[N - 2].n << endl;
    // long long m, n;
    // for (int i = 1; i < N; ++i)
    // {
    //     a[i] = lcm(a[i], a[i - 1]);
    // }
    // if (a[N - 1] % 2 == 0)
    // {
    //     m = a[N - 1] / 2;
    //     n = 1;
    // }
    // else
    // {
    //     m = a[N - 1];
    //     n = 2;
    // }
    // cout << m << " " << n << endl;
}