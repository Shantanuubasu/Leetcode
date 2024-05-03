class Solution {
public:

    vector<string> ver(string version){
        stringstream ss(version);

        string t="";
        vector<string> v;

        while(getline(ss,t,'.')){
            v.push_back(t);
        }

        return v;
    }

    int compareVersion(string version1, string version2) {

        vector<string> v1=ver(version1);
        vector<string> v2=ver(version2);

        int n=v1.size();
        int m=v2.size();
        int i=0;
        while(i<n || i<m){
            int a=i<n ? stoi(v1[i]) : 0;
            int b=i<m ? stoi(v2[i]) : 0;

            if(a>b){
                return 1;
            }
            else if(a<b){
                return -1;
            }
            else{
                i++;
            }
        }
        return 0;
    }
};

//-----------------------------------------------------------------
/* 1. We will solve this problem using stringstream method of C++.
2. We will pass both the strings to stringstream and get it back in form of a vector by removing `.`
3. Then we start comparing the vectors and return the value according to the condition in the question. */
