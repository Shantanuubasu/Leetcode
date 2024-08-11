class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j){
        if(i<0 || i>=visited.size() || j<0 || j>=visited[0].size() || visited[i][j] || grid[i][j]==0){
            return;
        }

        visited[i][j]=true;

        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);
    }

    int islands(vector<vector<int>>& grid){
        int c=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    dfs(grid, visited, i ,j);
                    c++;
                }
            }
        }

        return c;
    }


    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int c=islands(grid);

        if(c==0 || c>1){
            return 0;
        }
        else{
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        
                        c=islands(grid);
                        
                        grid[i][j]=1;

                        if(c==0 || c>1){
                            return 1;
                        }

                    }
                }
            }
        }

        return 2;

    }
};

//-----------------------------------------------------------------------
/* 1. First we find the number islands.
2. To find the number islands, we will use dfs to find the number of islands.
3. If the number of islands is equal to or greater than 1 then return 0.
4. If not then make every 1 as 0 and check if it retruns more than 1 or 0 islands if yes then return 1.
5. If the above conditions doesn't work, return 2. */
