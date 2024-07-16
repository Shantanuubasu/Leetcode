class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num=start^goal;
        int c=0;
        while(num!=0){
            c+=num&1;
            num=num>>1;
        }

        return c;
    }
};

//------------------------------------------------------------
/* 1. In this problem we basicall have to find the hamming distance, to find the hamming distance we calculate the xor of start and goal.
2. Now we will calculate the number of set bits in xor of start and goal.
3. To get set bits we can divide the num by 2 which is done by num>>1.
4. To count the number of set bits we can do num&1, which gives 1 when it is a set bit and 0 when it is not.
5. Finally, return c. */
