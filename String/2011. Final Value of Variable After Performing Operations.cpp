class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        ios_base::sync_with_stdio(false);

        int x=0;
        for(int i=0; i<operations.size(); i++){
            if(operations[i][1]=='-'){
                x--;
            }
            else{
                x++;
            }
        }

        return x;
    }
};

//----------------------------------------------------------------------
/* 1. Traverse in the operations array and check middle element of each string.
2. If it is - then decrement x.
3. If it is + then increment x.
4. Finally, return x. */
