class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios::sync_with_stdio(0),cin.tie(0);
        
        int row=matrix.size();
        int col=matrix[0].size();

        int r=0,c=col-1;
        while(r<row && c>=0){
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c]<target){
                r++;
            }
            else{
                c--;
            }

        }

        return false;
    }
};

//--------------------------------------------------------------
/* 1. So we will start looking for target starting from top right element.
2. If the element is equal to target then return true.
3. If the element is smaller than target then it means that the element cannot be found in this row, so we increment row value.
4. Else, we increment column because this row can contain target at different column.
5. If target is not found then return false. */
