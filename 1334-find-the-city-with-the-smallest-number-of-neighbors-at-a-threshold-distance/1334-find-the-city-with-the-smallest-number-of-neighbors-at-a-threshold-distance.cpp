class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=1e9 && dist[k][j]!=1e9){
                        dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        int cityMax = n;
        int cityNo = -1;
        
        for(int city = 0;city<n;city++){
            int cnt = 0;
            for(int adjCity=0;adjCity<n;adjCity++){
                if(dist[city][adjCity] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= cityMax){
                cityMax = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};