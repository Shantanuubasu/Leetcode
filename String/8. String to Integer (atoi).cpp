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
