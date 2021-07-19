// using BFS and inorder degree
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>inDegree(numCourses,0);
        queue<int>q;
        vector<list<int>> adj(numCourses);
        
        // converting vector into adj list
        
        // in Degree calculation
        for(int i=0;i<prerequisites.size();i++){
            inDegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        // pushing all nodes have zero indegree
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        // one by one trying topological sorting
        while(!q.empty()){
            int curr = q.front();q.pop();
            count++;
            for(auto x: adj[curr]){
                inDegree[x]--;
                if(inDegree[x]==0){
                    q.push(x);
                }
            }
        }
        return (count == numCourses)? true: false;
    }
};
