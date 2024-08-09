class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c){
        unordered_set<int> st;

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int num=grid[r+i][c+j];
                if(num<1 || num>9 || st.count(num)){
                    return false;
                }
                else{
                    st.insert(num);
                }
            }
        }

        int sum=grid[r][c]+grid[r][c+1]+grid[r][c+2];

        for(int i=0; i<3; i++){
            if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=sum){
                return false;
            }

            if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=sum){
                return false;
            }
        }

        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=sum){
            return false;
        }

        if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=sum){
            return false;
        }

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int c=0;

        for(int i=0; i<=rows-3; i++){
            for(int j=0; j<=cols-3; j++){
                if(isMagicSquare(grid, i, j)){
                    c++;
                }
            }
        }

        return c;
    }
};

//-------------------------------------------------------------------------
/* 1. We can go from 0 row-3 and 0 to col-3 to get 3x3 matrices.
2. In isMagicSquare(), We check if the num is between 1 to 9 and is distinct.
3. Now we check the sum for each row or column if they don't match we return false.
4. We also check for diagonal and antiu-diagonal sums.
5. If all the above conditions satisfy then we return true and increment c.
6. Finally, return c. */
