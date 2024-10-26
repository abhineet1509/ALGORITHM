#include<bits/stdc++.h>
using namespace std;
 int reverse(int arr[],int brr[],int start,int end){
    cout<<"reverse of array is"<<endl;
        for(int i=0;i<end+1;i++){
            brr[i]=arr[end-i];
        }
 }
int main(){
    int n;
    cin>>n;
    int arr[n];
    int i;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int brr[n];
    reverse(arr,brr,0,n-1);
       
    for(int i=0;i<n;i++){
        cout<<brr[i]<<" ";
    }cout<<endl;

}
