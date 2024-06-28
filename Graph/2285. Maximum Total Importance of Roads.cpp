class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);

        long long int res=0, cost=1;
        vector<int> nodes(n,0);
        for(auto &i: roads){
            nodes[i[0]]++;
            nodes[i[1]]++;
        }

        sort(nodes.begin(), nodes.end());
        for(int &i: nodes){
            res+=i*(cost);
            cost++;
        }

        return res;
    }
};

//------------------------------------------------------------------------------------
/* 1. We will store the number of edges for each node in a array.
2. Now we will sort the nodes array.
3. The goal is to assign lower cost to nodes with less number of edges and higher cost to nodes with high number of edges to maximize the cost.
4. So we will traverse in nodes array and add the multiplication of the no. of edges and cost to res for each node and increment cost.
5. Finally, return res. */
