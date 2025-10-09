#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
#include<queue>
#include <iomanip>
using namespace std;

int main() {
    int N, M;
    double alpha;
    cin >> N >> M >> alpha;

    vector<vector<pair<int, pair<double, int>>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, t;
        double p;
        cin >> u >> v >> t >> p;
        double priority = -log(p) + alpha * t;
        adj[u].push_back({v, {priority, t}});
        // If graph is undirected, also add:
        // adj[v].push_back({u, {priority, t}});
    }

    const double INF = 1e18;
    vector<double> prioarr(N + 1, INF);
    vector<int> timetaken(N + 1, INT_MAX);

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    prioarr[1] = 0.0;
    timetaken[1] = 0;
    pq.push({0.0, 1});

    while (!pq.empty()) {
        auto [currprio, u] = pq.top();
        pq.pop();
        if (currprio > prioarr[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            double priority = edge.second.first;
            int t = edge.second.second;

            double newprio = prioarr[u] + priority;
            int newTime = timetaken[u] + t;

            if (newprio < prioarr[v]) {
                prioarr[v] = newprio;
                timetaken[v] = newTime;
                pq.push({newprio, v});
            }
        }
    }

    if (prioarr[N] == INF)
        cout << -1 << "\n";
    else
        cout << fixed << setprecision(6) << prioarr[N] << " " << timetaken[N] << "\n";

    return 0;
}
