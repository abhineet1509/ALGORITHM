#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of the array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;
    cout<<"enter the index from where to rotate:";
    cin>>d;
    d=d%n;
    for(int j=d; j<n;j++){
        cout<<arr[j]<<" ";
    }
    for(int i=0;i<d;i++){
        cout<<arr[i]<<" ";
    } return 0;
}