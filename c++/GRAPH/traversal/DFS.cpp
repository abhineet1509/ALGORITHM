#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> DFSGraph(int v,vector<int>adj[]){
    queue<int> q;
    vector<bool> visited(v,0);
    q.push(0);
    visited[0]=1;
    vector<int> ans;
    while(!q.empty()){
       int node= q.front();
       q.pop();
       ans.push_back(node);
       for(int j=0;j<adj[node].size();j++){
        if(!visited[adj[node][j]]){
            visited[adj[node][j]]=1;
            q.push(adj[node][j]);
        }
       }
    } for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}
int main(){
    int vertex,edges;
    cout<<"no of vertex,no of edges:";
    cin>>vertex>>edges;
    vector<int> AdjList[vertex];
    int u,v;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u); 
    }
    for(int i=0;i<vertex;i++){
        cout<<i<<"->";
        for(int j=0;j<AdjList[i].size();j++){
            cout<<AdjList[i][j]<<" ";
            }cout<<endl;
    }
    DFSGraph(vertex,AdjList);
}