class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        
        // distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        // distance to itself = 0
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        
        // fill edges
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        // Floyd–Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        int ansCity = -1;
        int minCount = INF;
        
        // count reachable cities
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            
            // pick city with smaller count,
            // or larger index in case of tie
            if (count <= minCount) {
                minCount = count;
                ansCity = i;
            }
        }
        
        return ansCity;
    }
};
