#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    while(n!=0){
        v.push_back(n%2);
        n/=2;
    }
    vector<int> reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
}