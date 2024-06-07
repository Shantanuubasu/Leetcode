class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        string k=s;
        for(int i=0; i<s.size(); i++){
            s=k;
            reverse(s.begin(),s.end());
            reverse(s.begin(),s.begin()+i);
            reverse(s.begin()+i,s.end());
            if(s==goal){
                return true;
            }
        }

        return false;
    }
};

//-------------------------------------------------------------------
/* 1. If size of s and goal are different then return false.
2. Now we will reverse the string at every position to check if any combination is equal to goal or not.
3. If yes return true.
4. Else return false. */
