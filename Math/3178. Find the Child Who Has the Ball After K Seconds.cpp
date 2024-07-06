class Solution {
public:
    int numberOfChild(int n, int k) {
        ios_base::sync_with_stdio(false);

        int rounds=k/(n-1);
        int num=k%(n-1);
        if(rounds%2==0){
            return num; 
        }
        else{
            return n-num-1;
        }

        return -1;

    }
};

//----------------------------------------------------------
/* 1. We will first calculate the number of rounds taken.
2. Then we will calculate the time left after taking full rounds.
3. If rounds is even that means we are at 0th person so we return num.
4. Else, we are at the last person so we return n-num-1. */
