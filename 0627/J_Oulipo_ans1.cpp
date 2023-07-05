#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[1000005], t[10005]; //
int nex[10005], ans, n, lens, lent;
inline void getnex()
{
    int j = -1;
    for (int i = 0; i < lent; i++)
    {
        while (t[i] != t[j + 1] && j != -1)
            j = nex[j];
        if (t[i] == t[j + 1] && i != 0)
            j++;
        nex[i] = j;
    }
}
inline void kmp()
{
    int j = -1;
    for (int i = 0; i < lens; i++)
    {
        while (s[i] != t[j + 1] && j != -1)
            j = nex[j];
        if (s[i] == t[j + 1])
            j++;
        if (j == lent - 1)
            ans++, j = nex[j];
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        scanf("%s %s", t, s);
        lens = strlen(s);
        lent = strlen(t);
        getnex();
        kmp();
        printf("%d\n", ans);
    }
}