#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of array";
    cin>>n;
     int arr[n];
     cout<<"Enter th elements of the array";
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
     int x;
     cout<<"Enter the number whose sum has to be find";
     cin>>x;
     int i,j;
     for( i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(x==arr[i]+arr[j]){
               cout<<"yes";
            }
        }  cout<<arr[i],arr[j];
     } 
    return 0;
}