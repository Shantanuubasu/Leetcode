class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;

        for(int i=0; i<details.size(); i++){
            int n1=details[i][11];
            int n2=details[i][12];
            if(n1>'6' || (n1=='6' && n2>'0')){
                ans+=1;
            }
        }

        return ans;
    }
};

//--------------------------------------------------------------
/* 1. For each details check if the 11th index element is greater than '6' then increment ans.
2. Or if 11th index element is '6' and 12th  index element is greater than '0' then increment ans.
3. Finally, return ans. */
