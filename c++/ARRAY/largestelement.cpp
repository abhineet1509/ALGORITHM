#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
       int max =INT_MIN;       // int largest=INT_MIN;
    for(int i=1;i<n;i++){    //for(int i=0;i<n;i++)
        if(max>arr[i]){        // if(largest<arr[i])
        max=arr[i];}}          //largest=arr[i];
       cout<<max;              //cout<<largest;
    
    return 0;
}