class Solution {
private:
    void bfs(int node, vector<int> adjLs[], int vis[]) {
        vis[node] = 1;
        queue <int> q;
        q.push(node); 
        
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            
            for(auto adjNodes: adjLs[i]) {   
                if(vis[adjNodes] != 1) {
                    vis[adjNodes] = 1;
                    q.push(adjNodes);
                }
            }
        }
        
    }

public:
    int findCircleNum(vector<vector<int>> adj) {
        int V = adj.size();
        vector<int> adjLs[V];
        
        for(int i=0; i < V; i++) {
            for(int j=0; j < V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        
        int *vis = new int[V];
        for(int i = 0; i < V; i++)
            *(vis + i) = 0;
            
        int cnt = 0; 
        
        for(int i=0; i < V; i++) {
            if(!vis[i]) {
                cnt++;
                bfs(i, adjLs, vis); 
            }
        }
        
        return cnt; 
    }
};
