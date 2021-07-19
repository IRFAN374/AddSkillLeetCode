class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       int minEdge = n-1;
       int givenEdge = connections.size();
        vector<list<int>>adj(n);
        for(int i=0;i<givenEdge;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            
        }
        // printing adjacency list
        // for(int i=0;i<n;i++){
        //     cout<<i<<" ";
        //     for(auto x: adj[i]){
        //         cout<<"-->"<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        int count =0;
        vector<bool>visit(n,false);
        for(int i=0;i<n;i++){
            if(visit[i]==false){
                DFS(adj,visit,i);
                count++;
            }
        }
         // cout<<count<<endl;
        if(minEdge > givenEdge) return -1;
        return count-1;
        
    }
    void DFS(vector<list<int>>&adj, vector<bool>&visit,int src){
        visit[src]=true;
        for(auto x: adj[src]){
            if(visit[x]== false){
                DFS(adj,visit,x);
            }
        }
