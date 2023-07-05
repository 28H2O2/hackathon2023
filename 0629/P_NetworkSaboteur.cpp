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

bool Kernighan_Lin(unordered_set<int> &A, unordered_set<int> &B, vector<vector<int>> &Graph, int N)
{
    vector<int> sum_larger;
    vector<int> number;
    vector<int> direction; //* a->b is 1; b->a is -1;
    int a = 0;
    int b = 0;
    if (A.size() > 0)
    {
        for (auto it = A.begin(); it != A.end(); ++it)
        {
            a = *it;
            // cout << "aa = " << aa << endl;
            // B.insert(aa);
            // A.erase(aa);

            unordered_set<int> A_copy(A);
            unordered_set<int> B_copy(B);
            B_copy.insert(a);
            A_copy.erase(a);
            int current_sum = cal_sum(A_copy, B_copy, Graph);
            if (current_sum > sum)
            {
                sum_larger.push_back(current_sum);
                number.push_back(a);
                direction.push_back(1);
            }
            // A.insert(aa);
            // B.erase(aa);
        }
    }
    if (B.size() > 0)
    {
        for (auto it = B.begin(); it != B.end(); ++it)
        {
            b = *it;
            // cout << "bb = " << bb << endl;
            // A.insert(bb);
            // B.erase(bb);
            unordered_set<int> A_copy(A);
            unordered_set<int> B_copy(B);
            A_copy.insert(b);
            B_copy.erase(b);
            int current_sum = cal_sum(A_copy, B_copy, Graph);
            if (current_sum > sum)
            {
                sum_larger.push_back(current_sum);
                number.push_back(b);
                direction.push_back(-1);
            }
            // B.insert(bb);
            // A.erase(bb);
        }
    }
    if (sum_larger.empty() == true)
        return true;
    else
    {
        auto maxElement = std::max_element(sum_larger.begin(), sum_larger.end());
        if (maxElement != sum_larger.end())
        {
            int max_index = std::distance(sum_larger.begin(), maxElement);
            if (direction[max_index] == 1)
            {
                B.insert(number[max_index]);
                A.erase(number[max_index]);
            }
            else
            {
                A.insert(number[max_index]);
                B.erase(number[max_index]);
            }
        }
        sum = *maxElement;
        return false;
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
    sum = cal_sum(A, B, Graph);
    while (1)
    {
        if (Kernighan_Lin(A, B, Graph, N) == true)
        {
            cout << sum;
            break;
        }
        // cout << "sum = " << sum << endl;
    }
}

// unordered_set:
// https://www.cnblogs.com/JCpeng/p/15227986.html