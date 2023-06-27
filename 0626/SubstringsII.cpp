// F
#include <iostream>
#include <array> // 数组标准库
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int Q, A, B;
    const int size = 80000;
    char str[size];
    cin.getline(str, size);
    cin >> Q >> A >> B;
    getchar();
    char input[size];
    for (int i = 0; i < Q; ++i)
    {
        cin.getline(input, size);
        string str_new(input);
        char *p_begin;
        p_begin = str;
        char *p_find = NULL;
        int ans = 0;
        bool flag = true;

        while (1)
        {
            size_t pos = 0;
            string string_begin(p_begin);
            if ((pos = string_begin.find(input, pos)) == string::npos)
            {
                flag = false;
                break;
            }
            else
            {
                ans++;
                p_begin = p_begin + pos + 1;
                // p_find = strstr(p_begin, input);
                // p_begin = p_find + 1;
            }
            // cout << "pos = " << pos << endl;
            // break;
        }
        cout << ans << endl;
        int order = (A * ans + B) % 26 + 1;
        char new_letter = (char)(order + 96);
        int length = strlen(str);
        str[length] = new_letter;
        // cout << "new_letter = " << new_letter << endl;
    }
}