#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertex,edges;
    cout<<"no of vertex,no of edges:";
    cin>>vertex>>edges;
    vector<vector<int>> Adjmatrix(vertex,vector<int>(vertex,0));
    int u,v,weight;
    for(int i=0;i<edges;i++){
        cin>>u>>v>>weight;
        Adjmatrix[u][v]=weight;
        Adjmatrix[v][u]=weight;   //for directed delete this line
    }
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<Adjmatrix[i][j]<<" ";
        }cout<<endl;
    }
}