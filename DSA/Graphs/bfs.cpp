class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void BFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<int>&result){
        queue<int>q;
        q.push(u);
        visited[u] = true;
        result.push_back(u);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v:adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &mp) {
        // Code here
        unordered_map<int,vector<int>>adj;
        int v = mp.size();
        for(int u=0;u<v;u++){
            for(int j = 0;j<mp[u].size();j++){
                adj[u].push_back(mp[u][j]);
                // cout << mp[u][j] << " ";
            }
            // cout << endl;
        }
        vector<bool>visited(v,false);
        vector<int>result;
        BFS(adj,0,visited,result);
        return result;
        
    }
};