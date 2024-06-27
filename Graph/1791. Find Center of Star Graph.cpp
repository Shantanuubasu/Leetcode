class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);

        if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]){
            return edges[0][0];
        }
        else{
            return edges[0][1];
        }

        return 0;
    }
};

//--------------------------------------------------------------------------
/* 1. Atleast 3 nodes should be present in the graph for a center to be there.
2. As every node is connected to center, there will be a common edge in between.
3. We can find the common edge for first 2 nodes and return it. */
