class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        ios_base::sync_with_stdio(false);

        int odd=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]%2!=0){
                odd++;
            }
            else{
                odd=0;
            }

            if(odd==3){
                return true;
            }
        }

        return false;
    }
};

//----------------------------------------------------------------
/* 1. We check if the current element in the array is odd or not, if yes then increment odd.
2. Else, make odd as 0.
3. If odd becomes 3 then return true.
4. Otherwise, return false. */
