class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Build the adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            graph[from].push_back({to, weight});
            graph[to].push_back({from, weight});
        }
        
        int minReachable = n; // Start with the max possible
        int resultCity = -1;
        
        // Run Dijkstra from each city
        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});
            
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                for (auto& [v, w] : graph[u]) {
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            
            // Count reachable cities within the threshold (exclude self)
            int reachable = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[j] <= distanceThreshold) {
                    ++reachable;
                }
            }
            
            // Update result as per problem statement
            if (reachable <= minReachable) {
                minReachable = reachable;
                resultCity = i;
            }
        }
        return resultCity;
    }
};