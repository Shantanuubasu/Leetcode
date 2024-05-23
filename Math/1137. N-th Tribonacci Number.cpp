class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1 || n==2){
            return 1;
        }
        int t0=0,t1=1,t2=1;
        for(int i=0; i<=n-3; i++){
            int t=t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=t;
        }

        return t2;
    }
};

//---------------------------------------------------------------
/* 1. If n=0 then we will return 0.
2. If n==1 or n==2 then we return 1.
3. We will iterate from 0 to n-3 as we already have assigned values to the first 3 elements.
4. We will calculate the sum of the three elements and move the variables to its next variable.
5. Finally return t2. */
