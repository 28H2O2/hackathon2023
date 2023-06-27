// B Accepted
#include <iostream>
#include <array> // 数组标准库
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int T, n, B;
    int num = 0;
    while (1)
    {
        num++;
        cin >> T >> n >> B;
        double all;
        all = 0;
        vector<pair<double, int>> data(100000);
        if (T == 0 && n == 0 && B == 0)
            break;
        for (int i = 0; i < T; i++)
        {
            cin >> data[i].first >> data[i].second;
            data[i].second = 100 - data[i].second;
            all += data[i].first * data[i].second / 100;
        }
        all = all / B;
        printf("Case %d: %.2f\n", num, all);
        cout << endl;
    }
}