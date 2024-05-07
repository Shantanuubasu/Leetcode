class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);

        vector<int> ans;

        int n=matrix.size();
        int m=matrix[0].size();

        int left=0,right=m-1;
        int top=0,bottom=n-1;

        while(left<=right && top<=bottom){
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;;
            }

        }
        return ans;
    }
};

//--------------------------------------------------------------
/* 1. So this problem is simulation based.
2. We will keep four pointer left, right, top and bottom and keep iterating those in a cyclic way. */
