class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        ios_base::sync_with_stdio(false); 

        int i=m-1,j=n-1,k=m+n-1;
        
        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }
    }
};

//----------------------------------------------------------------------------
/* 1. We start iterating from back of both the arrays.
2. If the element of array 1 is greater than that of 2 we add element of array 1 to back of the array 1.
3. Otherwise add element of array 2. */
