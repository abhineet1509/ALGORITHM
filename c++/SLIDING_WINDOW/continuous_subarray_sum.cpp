#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int continuous_subarray(vector<int> &v,int n,int k){
    int sum = 0;
   int res =0;
   int  i=0,j=0;
   int length = 0;
   int mini=INT_MIN;
   while(j<k){
    sum+=v[i];
    if(sum%k==0){
      length = j-i+1;
      mini = max(length,mini);
      j++;
    }
    i++;
   }
}
int main(){
    int n;
    cin >> n;
    int  k;
    cin>> k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<continuous_subarray(v,n,k)
}