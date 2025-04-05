#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertex,edges;
    cout<<"no of vertex,no of edges:";
    cin>>vertex>>edges;
    vector<vector<int>> Adjmatrix(vertex,vector<int>(vertex,0));
    int u,v;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        Adjmatrix[u][v]=1;
        Adjmatrix[v][u]=1;
    }
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<Adjmatrix[i][j]<<" ";
        }cout<<endl;
    }
}