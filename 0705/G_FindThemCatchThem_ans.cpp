#include <stdio.h>
#include <string.h>
int arr[112345 * 2];
int f(int x)
{
    return arr[x] == x ? x : arr[x] = f(arr[x]);
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        for (int i = 0; i <= 2 * n; i++)
        {
            arr[i] = i;
        }

        char c[2];
        int a, b;

        while (m--)
        {
            scanf("%s%d%d", c, &a, &b);

            int x = f(a);
            int y = f(b);

            if (c[0] == 'D')
            {

                if (x != y)
                {

                    arr[x] = f(b + n);
                    arr[y] = f(a + n);
                }
            }
            else
            {

                if (x == y)
                {
                    printf("In the same gang.\n");
                }
                else if (x == f(b + n) || y == f(a + n))
                {
                    printf("In different gangs.\n");
                }
                else
                {
                    printf("Not sure yet.\n");
                }
            }
        }
    }

    return 0;
}
