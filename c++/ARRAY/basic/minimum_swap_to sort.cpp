#include <bits/stdc++.h>
using namespace std;

int minSwapsPos(vector<int>& arr){
    int n=arr.size(), ans=0;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++) vp[i]={arr[i],i};
    sort(vp.begin(),vp.end());

    for(int i=0;i<n;i++){
        while(vp[i].second!=i){
            swap(vp[i], vp[vp[i].second]);
            ans++;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={4,3,2,1};
    cout<<minSwapsPos(arr)<<endl;
}
