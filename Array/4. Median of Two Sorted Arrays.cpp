class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        
        vector<int> v1;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                v1.push_back(nums1[i]);
                i++;
            }
            else{
                v1.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i<nums1.size()){
            v1.push_back(nums1[i]);
            i++;
        }

        while(j<nums2.size()){
            v1.push_back(nums2[j]);
            j++;
        }

        double ans;
        int k=v1.size();
        if(k%2==0){
            ans=(float)(v1[(k)/2]+v1[((k)/2)-1])/2;
        }
        else{
            ans=(float)(v1[k/2]);
        }

        return ans;
    }
};

//------------------------------------------------------------------
/* 1. Merge both the arrays.
2. If the size of merge array is even then return average of n/2th and n/2 +1 th element.
3. Else, return n/2th element. */
