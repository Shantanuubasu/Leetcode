class Solution {
public:

    int maxLocal(vector<vector<int>>& grid,int row,int col){
        ios_base::sync_with_stdio(false);

        int mx=INT_MIN;

        for(int i=row; i<=row+2; i++){
            for(int j=col; j<=col+2; j++){
                mx=max(mx,grid[i][j]);
            }
        }

        return mx;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>> v(n-2,vector<int>(n-2));

        for(int i=0; i<n-2; i++){
            for(int j=0; j<n-2; j++){
                v[i][j]=maxLocal(grid,i,j);
            }
        }

        return v;
    }
};

//-------------------------------------------------------------------------------------
/* 1. We will find the local maxima for every n-2 x n-2 sub-matrix.
2. We will run two loops i and j for n-2 times because n-2 is the maximum limit till which a sub-matrix of size n-2 x n-2 can be found.
3. In maxLocal function we will return the maximum for a given sub-matrix.
4. For a given sub-matrix, row+2 and col+2 is the maximum limit so we will run two loops and find the maximum elemet in that. */
