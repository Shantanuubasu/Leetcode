class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);

        int n=matrix.size(); 
        int m=matrix[0].size();

        vector<int> rowMin;
        for(int i=0; i<n; i++){
            int rmin=INT_MAX;
            for(int j=0; j<m; j++){
                rmin=min(rmin, matrix[i][j]);
            }
            rowMin.push_back(rmin);
        }

        vector<int> colMax;
        for(int i=0; i<m; i++){
            int cmax=INT_MIN;
            for(int j=0; j<n; j++){
                cmax=max(cmax, matrix[j][i]);
            }
            colMax.push_back(cmax);
        }

        vector<int> luckyNum;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==rowMin[i] && matrix[i][j]==colMax[j]){
                    luckyNum.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNum;
    }
};

//-----------------------------------------------------------------------------------------
/* 1. First find the minimum of every row.
2. Then find the maximum of each column.
3. Then iterate in matrix and if a number is equal to rowmin and colmax elements then it is a lucky number so push it into the array.
4. Finally, return luckyNum. */
