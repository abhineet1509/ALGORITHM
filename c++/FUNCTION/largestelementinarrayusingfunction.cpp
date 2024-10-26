#include<iostream>
#include<climits>
using namespace std;
int maxelement(int arr[],int n)
    { int max=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(max>arr[i])
            {
                max=arr[i];
            }
            
        } 
        cout<<max;

    }
int main(){
    int n;
    cin>>n;
     int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    maxelement(arr,n);
    
}