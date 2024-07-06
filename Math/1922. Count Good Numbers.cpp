#define mod 1000000007
class Solution {
public:
    long long solve(long long num, long long x){
        if(x==0){
            return 1;
        }

        if(x%2==0){
            return (solve((num*num)%mod, x/2));
        }

        return (num*solve(num, (x-1)))%mod;
    }

    int countGoodNumbers(long long n) {
        ios_base::sync_with_stdio(false);

        long long even=n/2 + n%2;
        long long odd=n/2;        

        return (solve(5, even)*solve(4, odd))%mod;
    }
};

//-----------------------------------------------------------------
/* 1. The number of even places for n will be n/2 + n%2 and odd places will be n/2.
2. Now for each even place we have 5 numbers (0, 2, 4, 6, 8) and for each odd place we have 4 numbers (2, 3, 5, 7).
3. So our will be 4^odd * 5^even.
4. In the solve(), we calculate the value of 4^odd and 5^even. */
