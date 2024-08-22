class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int i=0;

        while(num){
            if((num&1)==0){
                ans+=1<<i;
            }

            i++;
            num=num>>1;
        }

        return ans;
    }
};

//--------------------------------------------------
/* 1. To find the complement of the number we can process bit by bit.
2. So for the num&1 is 0 then shift 1 upto i places and add to ans.
3. Increment i and shift num by one bit to process the next bit.
4. Finally, return ans. */
