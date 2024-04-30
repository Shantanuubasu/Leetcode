class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }

        return fib(n-1)+fib(n-2);
        
    }
};

//-------------------------------------------
//1. Use the formula `fib(n-1)+fib(n-2)` and recursion.
