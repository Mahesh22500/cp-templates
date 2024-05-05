#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v, w;
    bool operator<(const edge &rhs) const
    {
        return w > rhs.w;
    }
};

vector<int> parent, rank_;

int find(int i)
{
    if (i != parent[i])
        parent[i] = find(parent[i]);
    return parent[i];
}

void union_set(int i, int j)
{
    int ri = find(i), rj = find(j);
    if (ri != rj)
    {
        if (rank_[ri] > rank_[rj])
            swap(ri, rj);
        parent[ri] = rj;
        if (rank_[ri] == rank_[rj])
            rank_[rj]++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    vector<edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
    }
    parent.resize(n);
    rank_.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    priority_queue<edge> pq;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            pq.push({i, j, cost[i] + cost[j]});
    for (auto &e : edges)
        pq.push(e);
    int total_cost = 0;
    while (!pq.empty())
    {
        edge e = pq.top();
        pq.pop();
        if (find(e.u) != find(e.v))
        {
            total_cost += e.w;
            union_set(e.u, e.v);
        }
    }
    cout << total_cost << endl;
    return 0;
}