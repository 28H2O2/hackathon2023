// C accepted
#include <iostream>
#include <array> // 数组标准库
#include <vector>
using namespace std;

int main()
{
    int n;
    int m;
    while (cin >> n >> m)
    {
        const int people = n * 2;
        // char array[people];
        // array<char, people> round_table;
        // char round_table[people];
        vector<int> round_table(people);
        for (int i = 0; i < people; ++i)
        {
            round_table[i] = i;
        }
        int all_people = people;
        int index = 0;
        while (1)
        {
            // int index = (((index + m) % all_people) != 0) ? (index + m) % all_people - 1 : (all_people - 1);
            // cout << "m = " << m << endl;
            index = (index + m - 1) % all_people;
            // cout << "index = " << index << endl;
            // cout << "all_people = " << all_people << endl;
            // round_table[index] = 'B';
            round_table.erase(round_table.begin() + index);
            all_people--;
            if (all_people == n)
                break;
        }
        // // 输出vector里面的内容
        // for (const auto &elem : round_table)
        // {
        //     std::cout << elem << " ";
        // }
        // std::cout << std::endl;
        vector<char> round_table_output(people);
        // char round_table_output[2 * n];
        for (int i = 0; i < people; ++i)
        {
            round_table_output[i] = 'B';
        }
        for (const auto &elem : round_table)
        {
            round_table_output[elem] = 'G';
        }
        for (int i = 0; i < people; ++i)
        {
            if (round_table_output[i] == 'B')
                cout << 'B';
            else
                cout << 'G';
        }
        cout << endl
             << endl;
        round_table.clear();
        all_people = people;
        index = 0;
        for (int i = 0; i < people; ++i)
        {
            round_table_output[i] = 'G';
        }
    }
}