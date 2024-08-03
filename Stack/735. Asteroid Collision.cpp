class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.size()<2){
            return asteroids;
        }

        stack<int> st;

        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(asteroids[i])){
                    st.pop();
                }
                else if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }
            }

        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//-------------------------------------------------------------------------------------
/* 1. If the size of asteroids array is less than 2 then return array as it is.
2. If the element of the array is greater than 0 then push it into the stack.
3. Else, we have a negative number so we will pop till the stack is not empty and stack top is greater than 0 and stack top is less than absolute value of current array element.
4. Now if the stack is not empty and stack top is equal to current element of array then pop.
5. Else if stack is empty or stack top is a negative number then push current array element.
6. Now push all the elements of stack to ans array.
7. We need to reverse the ans array for correct sequence of asteroids.
8. Finally, return stack. */
