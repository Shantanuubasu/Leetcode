class Solution {
public:
    int ncr(int n, int r){
        long long int ans=1;

        for(int i=0; i<r; i++){
            ans=ans*(n-i);
            ans=ans/(i+1);
        }

        return (int)ans;
    }

    vector<vector<int>> generate(int numRows) {
        ios_base::sync_with_stdio(false);

        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            vector<int> temp;
            for(int j=1; j<=i; j++){
                temp.push_back(ncr(i-1,j-1));
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

//--------------------------------------------------------------
/* 1. We will solve this problem using the formula `nCr = n! / (r! * (n-r)!)`.
2. For every row and column pair we will generate the value at that index using ncr function.
3. This value will be first stored in a temporary vector.
4. Then the whole row will be push backed to the ans vector. */
