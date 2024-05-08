class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int n1=0,n2=0,c1=0,c2=0;

        for(auto num:nums){
            if(num==n1){
                c1++;
            }
            else if(num==n2){
                c2++;
            }
            else if(c1==0){
                n1=num;
                c1=1;
            }
            else if(c2==0){
                n2=num;
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }

        c1=c2=0;
        for(auto num:nums){
            if(num==n1){
                c1++;
            }
            else if(num==n2){
                c2++;
            }
        }

        if(c1> nums.size()/3 && c2> nums.size()/3){
            return {n1,n2};
        }
        else if(c1> nums.size()/3){
            return {n1};
        }
        else if(c2> nums.size()/3){
            return {n2};
        }

        return {};
    }
};

//------------------------------------------------------------------------
/* 1. So we will use Boyer-Moore voting algorithm to solve this problem.
2. So in an array there can be atmost 2 elements with count greater than n/3.
3. So we will find these two numbers then find their count.
4. After that we will return them. */
