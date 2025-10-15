#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;
int main() {
    int m, n;
    double alpha;
    cout << "Enter no.of vertices: ";
    cin >> m;
    cout << "Enter no.of edges: ";
    cin >> n;
    cout << "Enter the alpha value: ";
    cin >> alpha;
    vector<vector<pair<int, pair<double,int>>>> road(m); 
    int e1, e2, time;
    double prob;
    for(int i = 0; i < n; i++) {
        cout << "Enter as edge1 edge2 time probability: ";
        cin >> e1 >> e2 >> time >> prob;
        double priority = -log(prob) + alpha * time;
        road[e1].push_back({e2, {priority, time}});
    }
    using Node = pair<double,int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<double> prior(m, INT_MAX);
    vector<int> travel_time(m, INT_MAX);
    prior[0] = 0;
    travel_time[0] = 0;
    pq.push({0.0, 0}); 
    while(!pq.empty()) {
        auto [p, u] = pq.top();
        pq.pop();
        if(p > prior[u]) continue;
        for(auto &it : road[u]) {
            int v = it.first;
            double new_prior = p + it.second.first;
            int new_time = travel_time[u] + it.second.second;
            if(new_prior < prior[v]) {
                prior[v] = new_prior;
                travel_time[v] = new_time;
                pq.push({new_prior, v});
            }
        }
    }
    cout << "Minimum Priority = " << prior[m-1] << endl;
    cout << "Travel Time = " << travel_time[m-1] << endl;
    return 0;
}
