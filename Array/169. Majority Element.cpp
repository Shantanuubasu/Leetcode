//APPROACH-1-Boyer-Moore Majority Voting Algorithm 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int ele=0;
        for(int i=0; i<n; ++i){
            if(count==0){
                count++;
                ele=nums[i];
            }
            else if(nums[i]==ele){
                count++;
            }
            else{
                count--;
            }
        }

        return ele;
    }
};

//----------------------------------------------------------------
/* To solve this problem we will use Boyer-Moore Majority Voting Algorithm .
Using this algorithm, we keep two variables count and element, element variable will store our answer and count variable will store the count of a particular element.
If the count of a variable is 0 then that element is picked up, if there are any other occurrences of the element in the array then its count is incremented by 1, 
and if the element does not match then its count is decremented by 1. 
By doing this, if the element is not a majority one then its count will reach zero at some point then a new element will be picked up.
Finally, we will get the answer because the count of the majority element will never hit zero in the process. */

//APPROACH-2-HASH-MAP

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size()/2;
        
        for(auto i:nums){
            ++m[i];
        }

        int res=0;

        for(auto i:m){
            if(i.second>n){
                res=i.first;
            }
        }

        return res;

    }
};

//---------------------------------------------------------------
/* So we have to keep the count of each elememt in the array so the best possible way is to maintain a hash table using unordered map, 
So in this unordered map the element is mapped to its count every time we encounter the element we increase its count by 1. 
Now after this is over, we will iterate through the map and if the number having count greater than n, here n=nums.size()/2.
That number would be our answer so we will return that. */
