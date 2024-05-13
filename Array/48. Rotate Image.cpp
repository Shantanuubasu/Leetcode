class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix[0].size();

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

//---------------------------------------------------------------------
/* 1. First swap all the elements with its mirror elements, this will give the transpose of the matrix.
2. Then reverse every row of the matrix. */