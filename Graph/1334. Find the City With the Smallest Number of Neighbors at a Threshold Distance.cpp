class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        ios_base::sync_with_stdio(false);

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(vector<int> e: edges){
            dist[e[0]][e[1]]=e[2];
            dist[e[1]][e[0]]=e[2];
        }

        for(int i=0; i<n; i++){
            dist[i][i]=0;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k]==INT_MAX || dist[j][k]==INT_MAX){
                        continue;
                    }

                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        int minCity=INT_MAX;
        int cityNo=-1;
        for(int i=0; i<n; i++){
            int c=0;
            for(int j=0; j<n; j++){
                if(dist[i][j]<=distanceThreshold){
                    c++;
                }
            }

            if(c<=minCity){
                minCity=c;
                cityNo=i;
            }
        }

        return cityNo;
    }
};

//---------------------------------------------------------------------
/* 1. We will make a distance matrix and initialize it with INT_MAX.
2. Now we fill up the values in the matrix according to the weights between the nodes.
3. The distance of the node from itself will be 0 so we assign 0 to it in the matrix.
4. Now we will implement Floyd Warshall algorithm to assign the shortest distances between two nodes.
5. Now we will find the number of distances less than or equal to distanceThreshold for each city.
6. The city with minimum number of count will be the answer. If multiple cities have the same minimum number then the answer will be the city with greatest city number.
7. Finally, return cityNo. */
