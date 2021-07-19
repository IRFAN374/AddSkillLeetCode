// DFS appraoch using Stack
​
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool>visit(numCourses,false);
        vector<int>visited(numCourses,0);
        stack<int>nodeVisited;
        vector<list<int>> adj(numCourses);
        
        // vector into adjacancy list
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]); 
        }
        
        
        // cheking graph has cycle or not
        for(int i=0;i<numCourses;i++){
            if(hasCycle(adj,visited,i)){
                return {};
            }
        }
        
        // graph has no cycle then sort them according to topological
        for(int i=0;i<numCourses;i++){
            if(visit[i]==false){
                topological(adj,visit,nodeVisited,i);
            }
        }
        
        //
        vector<int>result;
        while(!nodeVisited.empty()){
            result.push_back(nodeVisited.top());
            nodeVisited.pop();
        }
        return result;
    }
    // graph has no cycle/ acycle graph--> apply topological sorting
    void topological(vector<list<int>>&adj,vector<bool>&visit,stack<int>&nodeVisited,int src){
        visit[src]=true;
        
        for(auto x: adj[src]){
            if(visit[x]==false){
                topological(adj,visit,nodeVisited,x);
            }
        }
        
        nodeVisited.push(src);
    }
    
    // checking graph has cycle or not
    bool hasCycle(vector<list<int>>&adj,vector<int>&visited,int src){
