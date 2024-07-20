class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        ios_base::sync_with_stdio(false);

        int n=rowSum.size();
        int m=colSum.size();

        vector<vector<int>> mat(n, vector<int>(m, 0));

        int i=0,j=0;

        while(i<n && j<m){
            mat[i][j]=min(rowSum[i], colSum[j]);

            rowSum[i]-=mat[i][j];
            colSum[j]-=mat[i][j];

            if(rowSum[i]==0){
                i++;
            }

            if(colSum[j]==0){
                j++;
            }
        }

        return mat;

    }
};

//-----------------------------------------------------------------------
/* 1. We create a n x m matrix.
2. Now for each element in the matrix we will assign the lowest of rowSum and colSum.
3. If rowSum reaches 0 then increment i, if colSum reaches 0 increment j.
4. Finally, return mat. */
