// H
// 求最小公倍数
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef struct
{
    int m;
    int n;
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

int lcm(int x, int y)
{
    int ans = x * y;
    while (x % y != 0)
    {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return ans / y;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    vector<fraction> b(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
        b[i].n = a[i];
        b[i].m = 2;
    }
    int m, n;
    for (int i = 1; i < N; ++i)
    {
        a[i] = lcm(a[i], a[i - 1]);
    }
    if (a[N - 1] % 2 == 0)
    {
        m = a[N - 1] / 2;
        n = 1;
    }
    else
    {
        m = a[n - 1];
        n = 2;
    }
    cout << m << " " << n << endl;
}