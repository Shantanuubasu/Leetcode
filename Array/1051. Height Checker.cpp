class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v(heights.begin(),heights.end());
        sort(v.begin(),v.end());
        int c=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]!=heights[i]){
                c++;
            }
        }

        return c;
    }
};

//----------------------------------------------------------------------
/* 1. Create a new array with contents of heights and sort it.
2. Now compare the two arrays and increment c if both the elements don't match.
3. Finally, return c. */
