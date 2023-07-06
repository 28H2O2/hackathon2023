// G
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int judge(int x1, int x2)
{
}
int insert()
{
}
int main()
{
    int M, N;
    int T;
    cin >> T;
    vector<char> type(T);
    for (int i = 0; i < T; ++i)
    {
        cin >> N >> M;
        type.clear();
        int x1, x2;
        for (int i = 0; i < M; ++i)
        {
            cin >> type[i];
            cin >> x1 >> x2;
            if (type[i] == 'A')
            {
                judge(x1, x2);
            }
            else
            {
                insert();
            }
        }
    }
}