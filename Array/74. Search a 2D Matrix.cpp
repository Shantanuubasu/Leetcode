class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(false);

        int row=matrix.size();
        int col=matrix[0].size();
        int low=0,high=row*col-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid/col][mid%col]==target){
                return true;
            }
            else if(matrix[mid/col][mid%col]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return false;
    }
};

//---------------------------------------------------------------------
/* 1. To implement binary search in a 2D Matrix, we will first find out the no. of rows and columns in the matrix.
2. Then we will define the low and high value, these value indicates each cell of the matrix.
3. Then inside the while loop we find the mid.
4. We compare the target element with the cell at mid/col and mid%col.
5. If the target is equal to the element at that position then we return true.
6. If the target is greater than element then we update low to mid+1.
7. Else we update high to mid-1. */
