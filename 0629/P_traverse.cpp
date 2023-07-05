// P
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void backtrack(const unordered_set<int> &originalSet, unordered_set<int> &subset1, unordered_set<int> &subset2, int index, vector<pair<unordered_set<int>, unordered_set<int>>> &results)
{
    // 遍历结束，将当前的分解结果存入结果集
    if (index >= originalSet.size())
    {
        results.push_back({subset1, subset2});
        return;
    }

    int element = *next(originalSet.begin(), index);

    // 将当前元素添加到subset1
    subset1.insert(element);
    backtrack(originalSet, subset1, subset2, index + 1, results);
    subset1.erase(element);

    // 将当前元素添加到subset2
    subset2.insert(element);
    backtrack(originalSet, subset1, subset2, index + 1, results);
    subset2.erase(element);
}

int main()
{
    unordered_set<int> originalSet = {1, 2, 3, 4};
    unordered_set<int> subset1, subset2;
    vector<pair<unordered_set<int>, unordered_set<int>>> results;

    backtrack(originalSet, subset1, subset2, 0, results);

    // 遍历所有分解结果
    for (const auto &result : results)
    {
        cout << "Subset 1: ";
        for (int element : result.first)
        {
            cout << element << " ";
        }

        cout << "\nSubset 2: ";
        for (int element : result.second)
        {
            cout << element << " ";
        }

        cout << endl;
    }

    return 0;
}
