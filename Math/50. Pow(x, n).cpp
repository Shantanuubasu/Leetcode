class Solution {
public:
    double solve(double x, long long int n){
        if(n==0){
            return 1;
        }

        if(n<0){
            return solve(1/x, -n);
        }

        if(n%2==0){
            return solve(x*x, n/2);
        }
        
        return x*solve(x*x, (n-1)/2);
    }

    double myPow(double x, int n) {
        return solve(x,(long)n);
    }
};

//--------------------------------------------------
/* 1. If the value of n is 0 then we return 1 as anything raised to 0 is 1.
2. If the n is negative then we make x as 1/x and n as -n.
3. If n is evene then we do x*x and make n as n/2.
4. If n is odd then we do x*solve(x*x, (n-1)/2). */
