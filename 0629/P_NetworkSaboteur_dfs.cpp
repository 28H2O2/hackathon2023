// P
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <algorithm>

using namespace std;

int sum = 0;

int cal_sum(unordered_set<int> &A, unordered_set<int> &B, vector<vector<int>> &Graph)
{
    int sum = 0;
    for (const auto &a : A)
    {
        for (const auto &b : B)
        {
            sum += Graph[a][b];
        }
    }
    return sum;
}

void dfs(unordered_set<int> A, unordered_set<int> B, vector<vector<int>> &Graph, int N)
{
    if (B.size() == 1)
    {
        return;
    }

    for (const auto &b : vector<int>(B.begin(), B.end()))
    {
        unordered_set<int> A_copy(A);
        unordered_set<int> B_copy(B);
        A_copy.insert(b);
        B_copy.erase(b);

        int val = cal_sum(A_copy, B_copy, Graph);
        if (val > sum)
        {
            sum = val;
            dfs(A_copy, B_copy, Graph, N);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> Graph(N);
    for (int i = 0; i < N; ++i)
    {
        Graph[i].insert(Graph[i].begin(), N, 0); //* init
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Graph[i][j];
        }
    }
    // 初始化两个集合
    unordered_set<int> A;
    unordered_set<int> B;
    // A.insert(0);
    for (int i = 0; i < N; ++i)
    {
        B.insert(i);
    }
    dfs(A, B, Graph, N);
    cout << sum << endl;
}

// unordered_set:
// https://www.cnblogs.com/JCpeng/p/15227986.html