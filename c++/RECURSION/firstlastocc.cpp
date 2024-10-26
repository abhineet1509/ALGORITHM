#include <iostream>
using namespace std;
int firstocc(int arr[], int n, int i, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == m)
        {
            cout << i << endl;
        }
    }
    // cout<<arr[i]<<endl;
}
int lastocc(int arr[], int n, int i, int m)
{
    int ros = lastocc(arr, n, i + 1, m);
    if (ros != -1)
    {
        return ros;
    }
    if (arr[i] == m)
    {
        return i;
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    firstocc(arr, n, 0, m);
    lastocc(arr, n, 0, m);
    return 0;
}
