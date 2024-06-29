class Solution {
public:
    void DFS(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited){
        visited[i]=true;

        for(int &j: adj[i]){
            if(visited[j]!=true){
                DFS(j, adj, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);

        vector<vector<int>> ans;
        unordered_map<int,vector<int>> adj;

        for(vector<int> &i:edges){
            int u=i[0];
            int v=i[1];

            adj[v].push_back(u);
        }

        for(int i=0; i<n; i++){
            vector<int> ancestor;
            vector<bool> visited(n, false);

            DFS(i, adj, visited);

            for(int j=0; j<n; j++){
                if(j==i){
                    continue;
                }
                if(visited[j]==true){
                    ancestor.push_back(j);
                }
            }

            ans.push_back(ancestor);
        }

        return ans;
    }
};

//-------------------------------------------------------------------
/* 1. We will make a adjacency list for reversed graph, means we will reverse the direction of the edges.
2. Now we will do th DFS for each node, for every node visited we will mark it as true.
3. Now we will traverse in visited and push all the true nodes in ancestor array.
4. Now we will add the ancestor array to ans.
5. Finally, return ans. */
