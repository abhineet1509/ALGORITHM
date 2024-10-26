#include<iostream>
#include<vector>
using namespace std;
void bubblesort(int n,vector<int> v){

    for(int i=0;i<n;i++){
        int index=i;
        for(int j=i;j<n-1;j++){
            if(v[index]>v[i]){
            index=j;
            }}
        int temp=v[index];
        v[index]=v[i];
        v[i]=temp;
    }
for(int i=0;i<n;i++){  // we can also use print function
       cout<<v[i]<<" ";
 }
}
int main(){
    int n;
    cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
    bubblesort(n,v);
    return 0;
}