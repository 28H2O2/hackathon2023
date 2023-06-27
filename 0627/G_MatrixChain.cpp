// G Accepted
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

struct Matrix
{
    char letter;
    int length;
    int width;
};

Matrix left_parentheses = {'(', 0, 0};
Matrix right_parentheses = {')', 0, 0};

int main()
{
    Matrix matrix_multiple(Matrix a, Matrix b, int sum);
    int num;
    cin >> num;
    vector<Matrix> matrix(num);
    // vector<char> letter(num);
    // vector<int> length(num);
    // vector<int> width(num);
    for (int i = 0; i < num; ++i)
    {
        cin >> matrix[i].letter >> matrix[i].length >> matrix[i].width;
        // cin >> letter[i] >> length[i] >> width[i];
    }
    getchar();
    const int size = 2000;
    char multi[size];
    while (1)
    {
        memset(multi, 0, sizeof(multi)); // 将 multi 数组清空
        cin.getline(multi, size);
        if (cin.eof())
        {
            // 读取到 EOF，跳出循环
            break;
        }
        stack<Matrix> multi_stack;
        int sum = 0;
        bool flag = true;
        for (int i = 0; i < strlen(multi); ++i)
        {
            if (multi[i] == '(')
            {
                // cout << "(" << endl;
                multi_stack.push(left_parentheses);
            }
            else if (multi[i] >= 'A' && multi[i] <= 'Z')
            {
                // cout << "letter" << endl;
                if (multi_stack.empty())
                {
                    break;
                }
                if (multi_stack.top().letter >= 'A' && multi_stack.top().letter <= 'Z')
                {
                    if (multi_stack.top().width != matrix[(int)(multi[i] - 'A')].length)
                    {
                        flag = false;
                        break;
                    }
                    Matrix result = matrix_multiple(multi_stack.top(), matrix[(int)(multi[i] - 'A')], sum);
                    sum += multi_stack.top().length * multi_stack.top().width * matrix[(int)(multi[i] - 'A')].width;
                    multi_stack.pop();
                    multi_stack.push(result);
                }
                else
                {
                    multi_stack.push(matrix[(int)(multi[i] - 'A')]);
                }
            }
            else if (multi[i] == ')')
            {
                // cout << ")" << endl;
                Matrix pop_matrix = multi_stack.top();
                multi_stack.pop();
                multi_stack.pop();
                if (multi_stack.empty())
                {
                    break;
                }
                else if (multi_stack.top().letter == '(')
                {
                    multi_stack.push(pop_matrix);
                }
                else // 如果是一个矩阵
                {
                    if (multi_stack.top().width != pop_matrix.length)
                    {
                        flag = false;
                        break;
                    }
                    Matrix result = matrix_multiple(multi_stack.top(), pop_matrix, sum);
                    sum += multi_stack.top().length * multi_stack.top().width * pop_matrix.width;
                    multi_stack.pop();
                    multi_stack.push(result);
                }
            }
        }
        if (flag == false)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << sum << endl;
        }
    }
}

Matrix matrix_multiple(Matrix a, Matrix b, int sum)
{
    Matrix result;
    result.letter = a.letter;
    result.length = a.length;
    result.width = b.width;
    sum += a.length * a.width * b.width;
    return result;
}