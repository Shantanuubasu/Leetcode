class Solution {
public:
    int minOperations(vector<string>& logs) {
        ios_base::sync_with_stdio(false);

        int moves=0;
        for(string &i: logs){
            if(i=="../"){
                if(moves!=0){
                    moves--;
                }
            }
            else if(i=="./"){
                continue;
            }
            else{
                moves++;
            }
        } 

        return moves;  
    }
};

//--------------------------------------------------------
/* 1. If we get ../ that means we are moving to the parent directory so we will go back and decrement moves only if moves is not zeros.
2. If we get ./ then we don't have to do anything so we will continue.
3. Else, we will be moving to a new directory so we make increment moves.
4. Finally, return moves. */
