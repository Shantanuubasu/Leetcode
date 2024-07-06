// APPROACH - 1 - ITERATIVE

class Solution {
public:
    int myAtoi(string s) {
        int i=0,pos_flag=0,neg_flag=0;
        int n=s.length();
        double ans=0;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='+'){
            pos_flag=1;
            i++;
        }
        if(s[i]=='-'){
            neg_flag=1;
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            ans*=10;
            ans+=s[i]-'0';
            i++;
        }
        if(neg_flag==1){
            ans=-ans;
        }
        if(neg_flag==1 && pos_flag==1){
            return 0;
        }
        if(ans>INT_MAX){
            ans=INT_MAX;
        }
        if(ans<INT_MIN){
            ans=INT_MIN;
        }
        return int(ans);

    }
};

//-----------------------------------------------------------
/* 1. First we will skip any leading whitespaces.
2. Now we will check if the number is positive or negative and use flag to mark it.
3. Now we constuct the integer and check if neg_flag was 1 then make ans negative.
4. If both neg_flag and pos_flag was 1 then return 0.
5. If ans is greater than INT_MAX then return INT_MAX.
6. If ans is less than INT_MIN then return INT_MIN.
7. Finally return integer ans. */
//---------------------------------------------------------------------------------------------

// APPROACH - 2 - RECURSIVE

class Solution {
public:
    int solveAtoi(string s, int sign, int i, long long int res){
        if(sign*res>=INT_MAX){
            return INT_MAX;
        }

        if(sign*res<=INT_MIN){
            return INT_MIN;
        }

        if(s[i]==' ' || !isdigit(s[i])){
            return sign*res;
        }

        return solveAtoi(s, sign, i+1, res*10+(s[i]-'0'));
    }
    int myAtoi(string s) {
        ios_base::sync_with_stdio(false);

        int sign=1;
        int flag=0;
        int i=0;

        while(i<s.size() && s[i]==' '){
            i++;
        }

        if(s[i]=='-'){
            sign=-1;
            flag++;
            i++;
        }
        if(s[i]=='+'){
            sign=1;
            flag++;
            i++;
        }

        if(flag>1){
            return 0;
        }

        return solveAtoi(s, sign, i , 0);
    }
};

//---------------------------------------------------------------------
/* 1. We will first move past all the whitespaces at the front then we will check for the sign of the number if incase both the signs are present then we return 0.
2. In solveAtoi(), we check if sign*res is greater than INT_MAX then return INT_MAX.
3. If sign*res is less than INT_MIN then return INT_MIN.
4. If we get any non-digit element or whitespace then we return res*sign.
5. Otherwise we call the function again with i as i+1 and res as res*10+(s[i]-'0'). */
