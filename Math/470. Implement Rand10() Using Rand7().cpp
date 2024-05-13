// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        ios_base::sync_with_stdio(false);
    
        int rand=INT_MAX;
        while(rand>=40){
            rand=7*(rand7()-1)+rand7()-1;
        }
        return (rand%10)+1;
    }
};

//-------------------------------------------------------------------
/* 1. We generate rate numbers in the range 0 to 49.
2. Since we need to implement Rand10, we would need a multiple of 10.
3. So the nearest multiple would be 40. If the generated number is grater than 40 then we discard it and try again.
4. Finally we return rand%10 + 1. */
