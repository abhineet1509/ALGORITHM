#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int arr[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>arr[i][j];
        }
    }
    int n,m;
    cin>>n>>m;
    int brr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>brr[i][j];
        }
    }
    int res[a][m];
    for(int i=0;i<a;i++){
        for(int j=0;j<m;j++){
            res[i][j]={0};
            for(int k=0;k<n;k++){
                res[i][j]=res[i][j]+arr[i][k]*brr[k][j];
            }
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<m;j++){
            cout<<res[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}