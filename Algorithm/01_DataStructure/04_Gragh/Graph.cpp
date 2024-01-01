#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Gragh
{
private:
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    Gragh(int size = 0);
    void resize(int size);
    void clear_visited();
    void add_edge(int u, int v);
    void delete_edge(int u, int v);
    void sort_adj();
    void print_adj();
    void DFS(int u);
    void BFS(int v);
    void Display();
};
Gragh::Gragh(int size)
{
    adj = vector<vector<int>>(size, vector<int>());
    visited = vector<bool>(size, false);
}
void Gragh::resize(int size)
{
    vector<vector<int>> a = adj;
    adj = vector<vector<int>>(size, vector<int>());
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
            adj[i].push_back(a[i][j]);
    vector<bool> v = visited;
    visited = vector<bool>(size, false);
    for (int i = 0; i < v.size(); i++)
        visited[i] = v[i];
}
void Gragh::clear_visited()
{
    for (int i = 0; i < visited.size(); i++)
        visited[i] = false;
}
void Gragh::add_edge(int u, int v)
{
    if (max(u, v) + 1 >= adj.size())
        resize(max(u, v) + 1);
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Gragh::delete_edge(int u, int v)
{
    for (int i = 0; i < adj[u].size(); i++)
        if (adj[u][i] == v)
        {
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    for (int i = 0; i < adj[v].size(); i++)
        if (adj[v][i] == u)
        {
            adj[v].erase(adj[v].begin() + i);
            break;
        }
}
void Gragh::sort_adj()
{
    for (int i = 0; i < adj.size(); i++)
        sort(adj[i].begin(), adj[i].end());
}
void Gragh::print_adj()
{
    sort_adj();
    for (int i = 1; i < adj.size(); i++)
    {
        if (adj[i].size() == 0)
            continue;
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}
void Gragh::DFS(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++)
        if (!visited[adj[u][i]])
            DFS(adj[u][i]);
}
void Gragh::BFS(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        v = q.front();
        q.pop();
        cout << v << " ";
        for (int i = 0; i < adj[v].size(); i++)
            if (!visited[adj[v][i]])
            {
                q.push(adj[v][i]);
                visited[adj[v][i]] = true;
            }
    }
}
void Gragh::Display()
{
    cout << "Adjacency List: " << endl;
    print_adj();

    cout << "DFS: ";
    DFS(1);
    cout << endl;
    clear_visited();

    cout << "BFS: ";
    BFS(1);
    cout << endl;
    clear_visited();
}

int main()
{
    Gragh *G = new Gragh();

    cout << "Add Edge:" << endl;
    G->add_edge(2, 5);
    G->add_edge(1, 3);
    G->add_edge(3, 4);
    G->add_edge(1, 2);
    G->add_edge(2, 4);
    G->add_edge(4, 5);
    G->add_edge(3, 5);
    G->Display();

    cout << "Delete Edge:" << endl;
    G->delete_edge(2, 5);
    G->delete_edge(4, 5);
    G->delete_edge(1, 3);
    G->delete_edge(3, 5);
    G->delete_edge(3, 4);
    G->Display();

    return 0;
}
