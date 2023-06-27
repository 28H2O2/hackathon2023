// C
#include <iostream>
#include <array> // 数组标准库
using namespace std;

int main()
{
    int n;
    int m;
    while (1)
    {
        cin >> n >> m;
        const int people = n * 2;
        // char array[people];
        // array<char, people> round_table;
        char round_table[people];
        int all_people = people;
        int index = 0;
        for (int i = 0; i < all_people; ++i)
        {
            round_table[i] = 'G';
        }
        while (1)
        {
            int index = (((index + m) % all_people) != 0) ? (index + m) % all_people - 1 : (all_people - 1);
            cout << "index = " << index << endl;
            cout << "all_people = " << all_people << endl;
            round_table[index] = 'B';
            all_people--;
            if (all_people == n)
                break;
        }

        for (int i = 0; i < people; ++i)
        {
            if (round_table[i] == 'B')
                cout << 'B';
            else
                cout << 'G';
        }
        cout << endl
             << endl;
    }
}