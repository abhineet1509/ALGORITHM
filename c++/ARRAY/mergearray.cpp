#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter the number of element of 1st array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    cout<<"enter the number of element of 2st array";
    int brr[m+n];
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
     for (int i = 0; i < m+n - 1; ++i) {
        for (int j = 0; j < m+n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for(int i=0;i<m+n;i++){
        cout<<arr[i];
    }
}