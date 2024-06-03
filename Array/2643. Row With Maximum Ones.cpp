class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        
        int idx=0,cnt_max=0;

        for(int i=0; i<mat.size(); i++){
            int cnt=0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j]){
                    cnt++;
                }
            }
            if(cnt>cnt_max){
                idx=i;
                cnt_max=cnt;
            }
        }

        return {idx,cnt_max};
    }
};

//-----------------------------------------------------------------
/* 1. Iterate in the matrix using 2 loops.
2. Count the number of 1 in that row.
3. If count is greater than max count of 1 then update idx and cnt_max.
4. Finally return idx and cnt_max. */
