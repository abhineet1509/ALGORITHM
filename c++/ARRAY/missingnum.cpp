#include<iostream>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    int brr[m];
    for(int j=0;j<m;j++){
        cin>>brr[j];
    }
    for(int k=0;k<n;k++){
        if(arr[i]==arr[j]){
            cout<<"given array is equal";
        }
        else {
            cout<<"given array is not equal";
            cout<<i<<arr[i]<<endl;
        }
    }

}
