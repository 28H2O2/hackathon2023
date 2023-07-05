// P
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <algorithm>

using namespace std;

int cal_sum(const unordered_set<int> &A, const unordered_set<int> &B, const vector<vector<int>> &Graph)
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

void backtrack(const vector<int> &originalSet, unordered_set<int> subset1, unordered_set<int> subset2, int index, vector<pair<unordered_set<int>, unordered_set<int>>> &results)
{
    if (index >= originalSet.size())
    {
        subset1.insert(0);
        results.push_back({subset1, subset2});
        return;
    }

    // int element = *next(originalSet.begin(), index);
    int element = originalSet[index];

    subset1.insert(element);
    backtrack(originalSet, subset1, subset2, index + 1, results);
    subset1.erase(element);

    subset2.insert(element);
    backtrack(originalSet, subset1, subset2, index + 1, results);
    subset2.erase(element);
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
    vector<int> origin;
    for (int i = 1; i < N; ++i)
    {
        origin.push_back(i);
    }
    unordered_set<int> A;
    // A.insert(0);
    unordered_set<int> B;
    vector<pair<unordered_set<int>, unordered_set<int>>> results;
    int max = 0;
    backtrack(origin, A, B, 0, results);
    // int total_num = (N - 2) * (N - 1) / 2;
    // vector<int> value(total_num);
    //* 遍历所有分解结果
    for (const auto &result : results)
    {
        int res_value = cal_sum(result.first, result.second, Graph);
        if (res_value > max)
        {
            max = res_value;
        }
    }
    cout << max << endl;
}