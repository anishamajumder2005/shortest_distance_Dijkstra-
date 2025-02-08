#include<bits/stdc++.h>
#include<./vector>
#include<./queue>
#include<./unordered_map>
#include<./unordered_set>
#include<./stack>
#include<./string>
using namespace std;
//DIJKSTRA'S ALGORITHM
vector<int> shortestpath(int V,vector<vector<int>>adj[],int S){
    vector<int>dist(V);
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[S]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
    minh.push(make_pair(dist[S],S));
    while(!minh.empty()){
        int d=minh.top().first;
        int node=minh.top().second;
        minh.pop();
        for(auto it:adj[node]){
            int edge=it[0];
            int wt=it[1];
            if(d+wt<dist[edge]){
                dist[edge]=d+wt;
                minh.push(make_pair(dist[edge],edge));
            }
        }
    }
    return dist;
}
//DIJKSTRA USING SET
/*vector<int> dijkstra(int V,vector<vector<int>>adj[],int S){
    set<pair<int,int>>st;
    vector<int>dist(V,INT_MAX);
    dist[S]=0;
    st.insert(make_pair(0,S));
    while(!st.empty()){
        auto it=*(st.begin());
        int d=it.first;
        int node=it.second;
        st.erase(it);
        for(auto i:adj[node]){
            int n=i[0];
            int wt=i[1];
            if(wt+d<dist[n]){
                if(dist[n]!=INT_MAX)st.erase({dist[n],n});
                dist[n]=wt+d;
                st.insert({dist[n],n});
                
            }
        }
        return dist;
    }
}*/
int main(){
    int V, E, S;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;
    
    vector<vector<int>> adj[V];
    cout << "Enter each edge in the format (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // If the graph is undirected, also add the reverse edge
        adj[v].push_back({u, w});
    }
    
    cout << "Enter the source vertex: ";
    cin >> S;
    
    vector<int> dist = shortestpath(V, adj, S);
    
    cout << "Shortest distances from source " << S << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : " << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
    }
    
    return 0;
}
