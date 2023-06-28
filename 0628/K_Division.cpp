// K Accepted
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

int main()
{
    bool check(int N, int a, int b);
    int N;
    int count = 0;
    while (1)
    {
        count++;
        bool flag = false;
        cin >> N;
        if (N == 0)
        {
            break;
        }
        else if (count > 1)
        {
            cout << endl;
        }
        else
        {
        }
        // int num1, num2;
        for (int num2 = 1234; num2 < 49876 && num2 * N < 98765; ++num2)
        {
            int num1 = num2 * N;
            if (check(N, num1, num2))
            {
                flag = true;
                if (num2 < 10000)
                {
                    cout << num1 << " / 0" << num2 << " = " << N << endl;
                }
                else
                {
                    cout << num1 << " / " << num2 << " = " << N << endl;
                }
            }
        }
        if (flag == false)
        {
            cout << "There are no solutions for " << N << "." << endl;
        }
    }
}

bool check(int N, int a, int b)
{
    // if (a / b != N)
    //     return false;
    // int num[10];
    unordered_set<int> numSet(10);
    int i = 0;
    while (a > 0)
    {
        numSet.insert(a % 10);
        i++;
        a /= 10;
    }
    while (i < 10)
    {
        numSet.insert(b % 10);
        i++;
        b /= 10;
    }
    // 检查是否包含0到9这些值
    for (int i = 0; i < 10; i++)
    {
        if (numSet.find(i) == numSet.end())
        {
            return false;
        }
    }
    return true;
}