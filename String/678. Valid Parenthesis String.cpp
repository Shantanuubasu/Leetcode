class Solution {
public:
    
    bool checkValidString(string s) {
        int min=0,max=0;

        for(char &c:s){
            if(c=='('){
                min++;
                max++;
            }
            else if(c==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }

            if(max<0){
                return false;
            }
            if(min<0){
                min=0;
            }
        }

        return min==0;
        
    }
};

//-----------------------------------------------------------------------
/* 1. we will use two variables min and max to keep track of minimum and maximum open brackets.
2. If we get ( we increment min and max.
3. If we get ) we decrement min and max.
4. If we get * then we decrement min and increment max.
5. If max<0 we return false and if min<0 then we reset min to 0.
6. Finally we check of min==0 and return that. */
