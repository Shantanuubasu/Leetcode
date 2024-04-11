class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k){
            return "0";
        }

        string ans;
        vector<char> stack;

        for(int i=0; i<num.length(); i++){
            while(k>0 && !stack.empty() && stack.back()>num[i]){
                stack.pop_back();
                k--;
            }
            stack.push_back(num[i]);
        }

        while(k>0){
            stack.pop_back();
            k--;
        }

        for(char &c : stack){
            if(c=='0' && ans.empty()){
                continue;
            }
            ans+=c;
        }

        return ans.empty() ? "0" : ans;
    }
};

//----------------------------------------------------------------------------------------
/* 1. We will iterate in the string `num` and check for every element if there is an element greater than that in the `stack` then we keep on popping it until `k==0`.
2. If even after this operation `k>0` then we will keep on popping until `k==0`.
3. To construct the `ans` string we will check if the element is `0` and `ans` is empty then we cannot add it to `ans` because there can never be leading `0s` and remaining elements are added to the `ans` string.
4. Finally we return `ans` or `0` if `ans` is empty. */
