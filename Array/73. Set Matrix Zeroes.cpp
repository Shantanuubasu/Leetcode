class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);

        int n=matrix.size();
        int m=matrix[0].size();

        int col0=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;

                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }

        if(matrix[0][0]==0){
            for(int j=0; j<m; j++){
                matrix[0][j]=0;
            }
        }

        if(col0==0){
            for(int i=0; i<n; i++){
                matrix[i][0]=0;
            }
        }

    }
};

//------------------------------------------------------------
/* 1. We will use the first row and first column to keep track of zeros.
2. We will set the corresponding value in first row column if a 0 occurs in corresponding row or column.
3. After that we will traverse again and make the row or column zero.
4. We will then check if `matrix[0][0]` is 0 or not. If yes make that row 0.
5. Now we will check for variable col0 which keep track if value of `matrix[0][0]` is changed or not. */
