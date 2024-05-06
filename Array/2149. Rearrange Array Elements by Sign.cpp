//APPROACH-1-USING TWO ARRAYS

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        vector<int> sub1;
        vector<int> sub2;
        int n=nums.size();
        for(int i=0; i<n; ++i){
            if(nums[i]<0){
                sub1.push_back(nums[i]);
            }
            else{
                sub2.push_back(nums[i]);
            }
        }
        vector<int> res;
        int sub1_ind=0;
        int sub2_ind=0;
        while(sub1_ind<n/2){
            res.push_back(sub2[sub2_ind]);
            ++sub2_ind;
            res.push_back(sub1[sub1_ind]);
            ++sub1_ind;
        }

        return res;

    }
};

//--------------------------------------------------------------
/* We have to create a resultant array with alternating postive and negative element starting with positive element.
So, first of all we will divide the nums array into sub parts of positive and negative. 
sub1 contains negative elements and sub2 contains positive elements.
Now after we obtain both the arrays, we will merge both accordingly. 
`sub1_ind` and `sub2_ind` will keep track of the indexes of the sub arrays.
Inside the while loop, we will first insert a positive element and then a negative element Finally, we will return the res array. */

//APPROACH-2-USING-ONE-ARRAY
