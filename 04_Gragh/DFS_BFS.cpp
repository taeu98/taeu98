#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<bool> visited(10002, false);
vector<int> graph[1002];

vector<int> ans_bfs;
vector<int> ans_dfs;

void BFS(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        ans_bfs.push_back(x);
        for (int i = 0; i < graph[x].size(); i++)
        {
            if (!visited[graph[x][i]])
            {
                q.push(graph[x][i]);
                visited[graph[x][i]] = true;
            }
        }
    }
}
void DFS(int x)
{
    visited[x] = true;
    ans_dfs.push_back(x);
    for (int i = 0; i < graph[x].size(); i++)
    {
        if (!visited[graph[x][i]])
            DFS(graph[x][i]);
    }
}

int main()
{
    int N, M, V;
    int x, y;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    DFS(V);
    for (int i : ans_dfs)
        cout << i << " ";
    cout << endl;

    visited.assign(10002, false);

    BFS(V);
    for (int i : ans_bfs)
        cout << i << " ";
    cout << endl;

    return 0;
}