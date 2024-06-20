class Solution {
public:
    bool countStore(vector<int>& quantities, int n, int mid){
        int stores=0;
        for(int i=0; i<quantities.size(); i++){
            stores+=ceil((double)quantities[i]/mid);
        }
        if(stores<=n){
            return true;
        }

        return false;
    }

    int maxele(vector<int> &quantities){
        int maxi=INT_MIN;
        for(int i=0; i<quantities.size(); i++){
            maxi=max(maxi,quantities[i]);
        }
        return maxi;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        ios_base::sync_with_stdio(false);

        int low=1,high=maxele(quantities);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(countStore(quantities,n,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};

//-------------------------------------------------------------------------
/* 1. We will use binary search, take low as 0 and high as max element of the array.
2. Calculate mid and find the number of stores that can be supplied with maximum mid number of products.
3. If number of stores is less than or equal to n then update high as mid-1 as we need to distribute lesser quantity of products.
4. Else, update low as mid+1.
5. Finally, return low. */
