class Solution {
public:
long long short_path(vector<vector<pair<int,int>>> &adj, int src, int des) {
    int n = adj.size();
    vector<long long> dist(n, -1);

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    dist[src] = 0;
    pq.emplace(0LL, src);

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        long long d = cur.first;
        int u = cur.second;

        if (u == des) return d;
        if (d != dist[u]) continue;

        for (auto &e : adj[u]) {
            int v = e.first;
            long long w = e.second;
            long long nd = d + w;

            if (dist[v] == -1 || nd < dist[v]) {
                dist[v] = nd;
                pq.emplace(nd, v);
            }
        }
    }

    return -1;
}

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> adj(26);
        for(int i = 0; i < cost.size(); i++){
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        int n = source.size();
        vector<vector<long long>> path(26, vector<long long>(26, -1));
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                path[i][j] = short_path(adj, i, j);
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long cur = path[source[i]-'a'][target[i]-'a'];
            if(cur == -1) return -1;
            ans += cur;
        }
        return ans;
    }
};