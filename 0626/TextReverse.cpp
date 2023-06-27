// E Accepted
#include <iostream>
#include <array> // 数组标准库
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int test_num;
    cin >> test_num;
    getchar();
    const int size = 1000;
    char str[size];
    for (int i = 0; i < test_num; ++i)
    {
        cin.getline(str, size);
        int len = strlen(str);
        char *p_begin;
        p_begin = str;
        char *p_end;
        char *p_next_space;
        bool flag = true;
        int j = 0;
        while (1)
        {
            // cout << "p_begin = " << *p_begin << endl;
            // p_next_space = strstr(p_end, " ");
            if (strstr(p_begin, " ") == NULL)
            {
                flag = false;
                // cout << "!!";
                p_end = &str[len - 1];
            }
            else
            {
                p_end = strstr(p_begin, " ") - 1;
            }

            // cout << "p_end = " << *p_end << endl;
            int change_length = (p_end - p_begin + 1) / 2;
            // cout << "length = " << change_length << endl;
            for (int i = 0; i < change_length; ++i)
            {
                char change = p_begin[i];
                p_begin[i] = p_end[-i];
                p_end[-i] = change;
            }
            // break;
            if (flag == false)
                break;
            p_begin = p_end + 2;
            j++;
            if (j == 100)
                break;
        }

        cout << str << endl;
    }
}