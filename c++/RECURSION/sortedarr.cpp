#include<iostream>
using namespace std;
bool sorted(int arr[],int n){
     if(n==1){
        return true;
     }
        bool ros=sorted(arr+1,n-1);
      return(arr[0]<arr[1] && ros);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<sorted(arr,n);
     return 0;
}