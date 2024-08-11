class Solution {
public:
    void dfs(vector<vector<int>>& m, int i, int j){
        if(i<0 || i>=m.size() || j<0 || j>=m[0].size() || m[i][j]==1){
            return;
        }

        m[i][j]=1;

        dfs(m, i+1, j);
        dfs(m, i-1, j);
        dfs(m, i, j+1);
        dfs(m, i, j-1);    
    }

    int regionsBySlashes(vector<string>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int regions=0;

        vector<vector<int>> m(rows*3, vector<int>(cols*3, 0));

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='/'){
                    m[i*3][j*3+2]=1;
                    m[i*3+1][j*3+1]=1;
                    m[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\'){
                    m[i*3][j*3]=1;
                    m[i*3+1][j*3+1]=1;
                    m[i*3+2][j*3+2]=1;
                }
            }
        }

        for(int i=0; i<m.size(); i++){
            for(int j=0; j<m[0].size(); j++){
                if(m[i][j]==0){
                    dfs(m, i, j);
                    regions++;
                }
            }
        }

        return regions;
    }
};

//------------------------------------------------------------------
/* 1. We can denote the slashes in the form of 3x3 matrices.
2. So / will be
```
0 0 1
0 1 0
1 0 0
```
3. And \ will be
```
1 0 0
0 1 0
0 0 1
```
4. The empty string will be 3x3 with all 0s.
5. So we will form a matrix with rows\*3, cols*3 and input the matirx values according to the given grid.
6. Now we will do dfs on regions with input 0 and increment regions.
7. In dfs(), if i or j exceeds the boundary or element at i,j is 1 then return.
8. Otherwise, Mark the element at i,j as 1.
9. Now call the dfs for adjacent positions, i.e, top, bottom ,left and right.
10. Finally, return regions. */
