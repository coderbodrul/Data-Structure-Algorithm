#include <bits/stdc++.h>
#define int long long
#define mx 100

using namespace std;

vector<pair<int, int>> edge[mx + 1];
int vis[mx + 1];
vector<pair<int, int>> ans;
pair<int, int> st;
int u;
int cost;

void prims() {

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, st});

    while(!q.empty()) {
        pair<int, pair<int, int>> fr;
        fr = q.top();
        q.pop();
        pair<int, int> p;
        p = fr.second;
        if (!vis[p.first] or !vis[p.second]) {
            ans.push_back(p);
            cost += fr.first;
        }
        u = p.second;
        vis[u] = 1;
        
        for (int i = 0; i < edge[u].size(); i++) {
            int v, w;
            v = edge[u][i].first;
            w = edge[u][i].second;
            if (!vis[v]) {
                q.push({w, {u, v}});
            }
            
        }
    }
}

 
int32_t main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, e;
    cin >> n >> e;

    int u, v, w;
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }


    st = {1, 1};
    cost = 0;
    memset(vis, 0, sizeof(vis));
    prims();

    // cerr << cost << endl;
    // for (auto x : ans) cerr << x.first << " " << x.second << endl;
 
    return 0;
}