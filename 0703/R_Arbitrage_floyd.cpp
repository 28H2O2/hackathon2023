// P Accepted
// 找到无向有权里面所有的环
// https://www.luogu.com.cn/problem/solution/SP9340
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int N = 30;
double a[N][N];

int visited[N] = {0};

bool ans = false;

typedef struct
{
    string cur1;
    string cur2;
    double rate;
} exchange;

void floyd(int n)
{
    for (int k = 0; k < n; ++k)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                if (a[j][i] < a[j][k] * a[k][i])
                {
                    a[j][i] = a[j][k] * a[k][i];
                }
            }
        }
    }
}

int main()
{

    vector<bool> answer;
    int n;
    int e;
    int num = 0;
    while (1)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                a[i][j] = 0.0;
        }
        ans = false;
        num++;
        cin >> n;
        if (n == 0)
            break;
        string input;
        // vector<string> currency(n);
        map<string, int> currency;
        for (int i = 0; i < n; ++i)
        {
            cin >> input;
            currency.insert({input, i});
        }
        cin >> e;
        vector<exchange> item(e);
        for (int i = 0; i < e; ++i)
        {
            cin >> item[i].cur1 >> item[i].rate >> item[i].cur2;
            a[currency[item[i].cur1]][currency[item[i].cur2]] = item[i].rate;
        }
        floyd(n);
        for (int i = 0; i < n; ++i)
        {
            if (a[i][i] > 1.0)
            {
                // cout << a[i][i] << endl;
                ans = true;
                break;
            }
        }
        answer.push_back(ans);
        cin.ignore();
        ans = false;
    }
    for (int i = 0; i < answer.size(); ++i)
    {

        if (answer[i] == true)
        {
            std::cout << "Case " << i + 1 << ": "
                      << "Yes" << endl;
        }
        else
        {
            std::cout << "Case " << i + 1 << ": "
                      << "No" << endl;
        }
    }
}