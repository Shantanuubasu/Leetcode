class Solution {
public:
    int hammingDistance(int x, int y) {
        int num=x^y;
        int c=0;
        while(num!=0){
            c+=num&1;
            num=num>>1;
        }

        return c;
    }
};

//-------------------------------------------------------------
/* 1. To find the hamming distance we calculate the xor of x and y.
2. Now we will calculate the number of set bits in xor of x and y.
3. To get set bits we can divide the num by 2 which is done by num>>1.
4. To count the number of set bits we can do num&1, which gives 1 when it is a set bit and 0 when it is not.
5. Finally, return c. */
