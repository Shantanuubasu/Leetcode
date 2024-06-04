class Solution {
public:
    int findmaxele(vector<vector<int>> mat, int mid){
        int n=mat.size();
        int maxele_idx=-1,maxele=-1;
        for(int i=0; i<n; i++){
            if(mat[i][mid]>maxele){
                maxele=mat[i][mid];
                maxele_idx=i;
            }
        }

        return maxele_idx;

    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);

        int col=mat[0].size();

        int low=0,high=col-1;

        while(low<=high){
            int mid=low+ (high-low)/2;
            int row=findmaxele(mat,mid);
            int ele=mat[row][mid];
            int left=mid-1>=0 ? mat[row][mid-1] : -1;
            int right=mid+1<col ? mat[row][mid+1] : -1;

            if(ele>left && ele>right){
                return {row,mid};
            }
            else if(ele<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return {};
    }
};

//--------------------------------------------------------------------------
/* 1. We will apply binary search on the columns, set low as 0 and high as col-1.
2. Find the mid and find the maximum element in the mid column and return its row.
3. Check the left and right elements of the element, if greater than both then return its indexes.
4. If the element is less than left then we update high as mid-1.
5. Else we update low as mid+1. */
