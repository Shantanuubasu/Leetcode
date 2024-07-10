class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1=0, num2=0;
        for(int i=1; i<=n; i++){
            if(i%m!=0){
                num1+=i;
            }
            else{
                num2+=i;
            }
        }

        return num1-num2;
    }
};

//------------------------------------------------
/* 1. If i is not divisible by m then we add i to num1.
2. If i is divisible by m then we add i to num2.
3. Finally, return num1-num2. */
