#include <iostream>
#include <array>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int p, q;
    for (int i = 0; i < num; ++i)
    {
        cin >> p >> q;
        int chess_size = p * q;
        vector<pair<char, int>> table(chess_size);
        vector<int> planar(chess_size);
        for (int row = 0; row < p; ++row)
        {
            for (int column = 0; column < q; ++column)
            {
                table[row * q + column].first = (char)(row + 65);
                table[row * q + column].second = column + 1;
            }
        }
    }
}

bool check_valid(int now)
{
}
