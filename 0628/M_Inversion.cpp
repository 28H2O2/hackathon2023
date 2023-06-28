// M Accepted
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

long long sum = 0;
long long merge(vector<long long> &arr, long long front, long long mid, long long end)
{
    vector<long long> temp(end - front + 1);
    long long inversions = 0;
    long long i = front;
    long long j = mid + 1;
    long long k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    for (long long k = front; k <= end; ++k)
    {
        arr[k] = temp[k - front];
    }
    return inversions;
}

long long Inversion_Cal(vector<long long> &arr, long long front, long long end)
{
    long long inversions = 0;
    long long mid;
    if (front >= end)
        return 0;
    else
    {
        // mid = front + (end - front) / 2;
        mid = (front + end) / 2;
    }
    inversions += Inversion_Cal(arr, front, mid);
    inversions += Inversion_Cal(arr, mid + 1, end);
    inversions += merge(arr, front, mid, end);
    return inversions;
}
int main()
{
    long long n;
    long long k;
    while (1)
    {
        sum = 0;
        cin >> n >> k;
        if (cin.eof())
        {
            // 读取到 EOF，跳出循环
            break;
        }
        vector<long long> arr(n);
        for (long long i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        sum = Inversion_Cal(arr, 0, arr.size() - 1);
        // cout << "sum = " << sum << endl;
        if (sum - k <= 0)
            cout << 0 << endl;
        else
            cout << sum - k << endl;
        arr.clear();
    }
}
