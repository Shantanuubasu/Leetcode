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

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n=nums.size();
        vector<int> res(n,0);
        int x=0,y=1;
        for(int i=0; i<n; ++i){
            if(nums[i]>=0){
                res[x]=nums[i];
                x+=2;
            }
            else{
                res[y]=nums[i];
                y+=2;
            }
        }
        return res;

    }
};

//--------------------------------------------------------------------------
/* 1. We will add the elements to another array according to their value.
2. We will take one pointer to start from 0 which will add all the positive element in the array.
3. Another pointer will start from 11 which will add all the negative elements in the array. */
