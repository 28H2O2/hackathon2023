// P
// 找到无向有权里面所有的环
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

unordered_set<int> visited_vertice;
void findCycle(int init, double rate_mul, int current, int n)
{
    visited[current] = 1;
    // std::cout << "current_rate = " << rate_mul << endl;
    for (int i = 0; i < n; ++i)
    {
        if (ans)
        {
            return;
        }
        if (i == init && a[current][init] > 0.0000001)
        {
            rate_mul *= a[current][init];
            if (rate_mul > 1.0)
            {
                ans = true;
            }
            return;
        }
        if (i == current)
            continue;
        if (visited[i] == 1)
            continue;
        // auto it = visited_vertice.find(i);
        // if (it == visited_vertice.end())
        //     continue;
        if (a[current][i] > 0.0000001)
        {
            // visited_vertice.insert(i);
            double prev_rate_mul = rate_mul;
            visited[i] = 1;
            rate_mul *= a[current][i];
            findCycle(init, rate_mul, i, n);
            rate_mul = prev_rate_mul;
        }
    }
    visited[current] = 0;
    return;
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
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                visited[j] = 0;
            }
            visited[i] = 1;
            // visited_vertice.clear();
            // visited_vertice.insert(i);
            findCycle(i, 1, i, n);
            if (ans == true)
            {
                break;
            }
        }
        answer.push_back(ans);
        cin.ignore();
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