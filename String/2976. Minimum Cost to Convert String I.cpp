class Solution {
public:
    void floydWarshall(vector<vector<long long>> &dist, vector<char> &original, vector<char> &changed, vector<int> &cost){
        for(int i=0; i<original.size(); i++){
            dist[original[i]-'a'][changed[i]-'a']=min(dist[original[i]-'a'][changed[i]-'a'], (long long)cost[i]);
        }

        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ios_base::sync_with_stdio(false);

        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));

        floydWarshall(dist, original, changed, cost);

        long long ans=0;
        for(int i=0; i<source.length(); i++){
            if(source[i]==target[i]){
                continue;
            }

            if(dist[source[i]-'a'][target[i]-'a']==INT_MAX){
                return -1;
            }

            ans+=dist[source[i]-'a'][target[i]-'a'];
        }

        return ans;

    }
};

//---------------------------------------------------------------------------------
/* 1. We will use Floyd Warshall algorithm to find the minimum cost to convert one character to another.
2. We will create a distance matrix and it will be used in FW algorithm to fill the shortest distances. Distances here represent the cost of converting.
3. Then we will traverse in source, if character of both source and target is same then continue, we do not need to change.
4. If the distance between the source element and target element is INT_MAX then it means we cannot convert so we return -1.
5. Otherwise, add the cost of converting to ans.
6. Finally, return ans. */
