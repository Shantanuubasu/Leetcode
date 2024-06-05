/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        ios_base::sync_with_stdio(false);

        int low=1,high=n;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(guess(mid)==0){
                return mid;
            }
            else if(guess(mid)==-1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return 0;
    }
};

//-----------------------------------------------------------
/* 1. We will use binary search, take low as 1 and high as n.
2. Find mid, pass mid to guess API if return value is 0 then we return mid.
3. If API return value is -1, it means we have to find a smaller number so update high as mid-1.
4. If API return value is 1, it means we have to find a greater number so update low as mid+1. */
