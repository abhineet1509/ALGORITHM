#include<iostream>
using namespace std;
int reverse(int arr[],int start,int end){

    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
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
   reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
}
}