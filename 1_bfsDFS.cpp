#include <bits/stdc++.h>
using namespace std;
using intl = long long int;

vector<int> bfs(int sv, vector<int> adj[])
{
    vector<int> bfsOrder;
    vector<int> visited(9, 0);
    queue<int> q;
    visited[sv] = 1;
    q.push(sv);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfsOrder.push_back(node);

        for (auto &x : adj[node])
        {
            if (visited[x] == 0)
            {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
    return bfsOrder;
}
void dfs(int sv, vector<int> adj[], vector<int> &visited, vector<int> &dfsOrder)
{

    visited[sv] = 1;
    dfsOrder.push_back(sv);
    for (auto &x : adj[sv])
    {
        if (visited[x] == 0)
        {
            dfs(x, adj, visited, dfsOrder);
        }
    }
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int n = 8;
    vector<int> adj[n + 1];

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 5);
    addEdge(adj, 3, 6);
    addEdge(adj, 3, 7);
    addEdge(adj, 4, 7);
    addEdge(adj, 5, 8);
    addEdge(adj, 6, 8);

    vector<int> dfsOrder;
    vector<int> visited(n + 1, 0);
    int sv = 1;
    dfs(sv, adj, visited, dfsOrder);
    for (auto &x : dfsOrder)
        cout << x << " ";
    cout << endl;
    vector<int> bfsOrder = bfs(sv, adj);

    for (auto &x : bfsOrder)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}