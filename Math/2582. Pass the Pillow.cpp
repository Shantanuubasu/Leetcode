class Solution {
public:
    int passThePillow(int n, int time) {
        int rounds=time/(n-1);
        int num=time%(n-1);
        if(rounds%2==0){
            return num+1; 
        }
        else{
            return n-num;
        }

        return -1;

    }
};

//---------------------------------------------------
/* 1. We will first calculate the number of rounds taken.
2. Then we will calculate the time left after taking full rounds.
3. If rounds is even that means we are at 1st person so we return num+1.
4. Else, we are at the last person so we return n-num. */
