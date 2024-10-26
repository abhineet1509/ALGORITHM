#include<iostream>
using namespace std;
int main (){
     int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    } 
    int x=((n+1)*(n+2))/2;
    cout<<x-sum<<endl;
}