#include <bits/stdc++.h>
using namespace std;
using intl = long long int;
void addEdge(vector<pair<int, int>> adj[], int u, int v, int cost)
{
    adj[u].push_back({v, cost});
    adj[v].push_back({u, cost});
}
vector<int> dijkstrasAlgo(int sv, int vertices, vector<pair<int, int>> adj[])
{
    vector<int> distance(vertices + 1, 1e9);
    // pq with {dist,node};in c++ default pq is maxheap so make it minheap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[sv] = 0;
    pq.push({0, sv});

    while (!pq.empty())
    {
        int currNode = pq.top().second;
        int currCost = pq.top().first;
        pq.pop();

        for (auto &x : adj[currNode])
        {
            int neighNode = x.first;
            int edgeCost = x.second;

            if (distance[neighNode] > currCost + edgeCost)
            {
                distance[neighNode] = currCost + edgeCost;
                pq.push({distance[neighNode], neighNode});
            }
        }
    }
    return distance;
}
int main()
{
    int n = 8;
    vector<pair<int, int>> adj[n + 1];

    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 4, 2);
    addEdge(adj, 2, 3, 2);
    addEdge(adj, 2, 8, 1);
    addEdge(adj, 3, 5, 4);
    addEdge(adj, 3, 6, 4);
    addEdge(adj, 3, 7, 2);
    addEdge(adj, 4, 7, 3);
    addEdge(adj, 5, 8, 2);
    addEdge(adj, 6, 8, 2);

    int sv = 1;
    vector<int> distance = dijkstrasAlgo(sv, n, adj);
    for (int i = 1; i < n + 1; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
    return 0;
}