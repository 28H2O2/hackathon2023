// T Accepted
// 用归并排序的思想求逆序对
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
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
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        vector<long long> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        sum = Inversion_Cal(arr, 0, arr.size() - 1);
        cout << sum << endl;
        // 9 1 0 5 4
    }
}