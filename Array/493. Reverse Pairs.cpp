class Solution {
public:

    void merge(vector<int> &nums, int low, int mid, int high){
        int left=low;
        int right=mid+1;
        vector<int> temp;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low; i<=high; i++){
            nums[i]=temp[i-low];
        }
    }

    int pairs(vector<int> &nums, int low, int mid, int high){
        int cnt=0;
        int right=mid+1;
        for(int i=low; i<=mid; i++){
            while(right<=high && nums[i]> (long long)2*nums[right]){
                right++;
            }
            cnt+=(right-(mid+1));
        }

        return cnt;
    }

    int mergesort(vector<int> &nums, int low, int high){
        int cnt=0;
        if(low>=high){
            return cnt;
        }
        int mid=(low+high)/2;
        cnt+=mergesort(nums,low,mid);
        cnt+=mergesort(nums,mid+1,high);
        cnt+=pairs(nums,low,mid,high);
        merge(nums,low,mid,high);

        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::ios_base::sync_with_stdio(false);

        return mergesort(nums,0,nums.size()-1);
    }
};

//-----------------------------------------------------------------
/* 1. We will use the merge sort, an additional pairs function is used to count the number of pairs.
2. In pairs function, we use two loops one from start of array to mid and other from mid+1 to end.
3. We check for the condition for each element in the other half of the array and add the count. */
