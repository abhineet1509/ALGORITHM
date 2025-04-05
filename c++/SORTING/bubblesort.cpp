#include <iostream>
#include <vector>
using namespace std;
void bubblesort(int n, vector<int> v)
{

    for (int i = 0; i < n; i++)
    { // n
        for (int j = 0; j < n - i - 1; j++)
        { // n-i
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    { // we can also use print function
        cout << v[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    bubblesort(n, v);
    return 0;
}