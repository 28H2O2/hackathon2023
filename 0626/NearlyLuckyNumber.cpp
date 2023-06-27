// E accpetd
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long input;
    scanf("%I64d", &input);
    string str = to_string(input);
    char ans1 = '4';
    char ans2 = '7';
    int sum;
    sum = count(str.begin(), str.end(), ans1) + count(str.begin(), str.end(), ans2); // 计算出现4和7的次数
    // cout << "sum = " << sum << endl;
    string str_ans = to_string(sum);
    if (count(str_ans.begin(), str_ans.end(), ans1) + count(str_ans.begin(), str_ans.end(), ans2) == str_ans.length())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}