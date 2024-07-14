// APPROACH - 1 - Iterative

class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i=0; i<31; i++){
            if(pow(2,i)==n){
                return true;
            }
        }
        return false;
    }
};

//-------------------------------------------------
/* So in this problem we to find if the given number can be expressed in the powers of 2 or not. 
So, it is given that it is with the power of 31, so we check all the powers of 2 upto 31 and if the number matches then we will return true. 
Otherwise, we return false. */
//-----------------------------------------------------------------------------------------------------------------------------------------------------

// APPROACH - 2 - BIT MANIPULATION

class Solution {
public:
    bool isPowerOfTwo(int n) {
        ios_base::sync_with_stdio(false);

        int x=1;
        while(x<=n){
            if(x==n){
                return true;;
            }
            if(x>=INT_MAX/2){
                break;
            }
            x=x<<1;
        }

        return false;
    }
};

//--------------------------------------------------------------
/* 1. we will shift x to left till we reach n.
2. If at any stage x equal to n then we return true.
3. If x is greater than INT_MAX/2 then break.
4. Else, we return false. */
