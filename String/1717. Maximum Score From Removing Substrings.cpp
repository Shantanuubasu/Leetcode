class Solution {
public:
    string remove(string str, string sub){
        stack<char> st;

        for(char &i: str){
            if(i==sub[1] && !st.empty() && st.top()==sub[0]){
                st.pop();
            }
            else{
                st.push(i);
            }
        }

        string newStr="";
        while(!st.empty()){
            newStr+=st.top();
            st.pop();
        }

        reverse(newStr.begin(), newStr.end());

        return newStr;
    }

    int maximumGain(string s, int x, int y) {
        ios_base::sync_with_stdio(false);

        string maxStr= (x>y) ? "ab" : "ba";
        string minStr= (x<y) ? "ab" : "ba";
        int score=0;

        string newStr=remove(s, maxStr);
        int len1=newStr.length();
        int charRemoved=s.length()-len1;
        
        score+=(charRemoved/2)*max(x,y);

        newStr=remove(newStr, minStr);
        int len2=newStr.length();
        charRemoved=len1-len2;

        score+=(charRemoved/2)*min(x,y);

        return score;
    }
};

//----------------------------------------------------------------
/* 1. We will first remove the substring which has higher score.
2. Then we calculate the number of pairs removed.
3. Then we remove the substring with lower score.
4. In remove(), we take stack and push elements into it.
5. If the current element is same as sub[1] and top element of stack is same as sub[0] then pop from stack.
6. Otherwise, push the element in the stack.
7. Now add all the element of stack to a string and reverse it and return the string.
8. Finally, return score. */
