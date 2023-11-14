// #include "test.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_matrix(vector<vector<int>> &matrix)
{
    cout << "[matrix]" << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void print_stack(vector<vector<int>> &stack)
{
    cout << "[stack]" << endl;
    for (int i = 0; i < stack.size(); i++)
    {
        cout << i << " : ";
        for (int j = 0; j < stack[i].size(); j++)
        {
            cout << stack[i][j] << " ";
        }
        cout << endl;
    }
}

void print_path(vector<pair<int, int>> &pair)
{
    cout << "[path] ";
    for (int i = 0; i < pair.size(); i++)
    {
        cout << pair[i].first << "(" << pair[i].second << ") ";
    }
    cout << endl;
}

int DFS(int start, vector<vector<int>> matrix, vector<vector<int>> stack)
{
    int prev, next, max = 0;
    vector<pair<int, int>> path;
    path.push_back(make_pair(start, 0));
    while (path.size() > 0)
    {
        if (stack[path.back().first].size() > 0)
        {
            prev = path.back().first;
            next = stack[path.back().first].back();
            stack[prev].pop_back();
            stack[next].erase(remove(stack[next].begin(), stack[next].end(), prev), stack[next].end());
            path.push_back(make_pair(next, path.back().second + matrix[prev][next]));
            if (path.back().second > max)
            {
                max = path.back().second;
            }
            // print_path(path);
        }
        else
        {

            path.pop_back();
            // print_path(path);
        }
    }
    // cout << "Maximal path length is " << max << endl;
    return max;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> Matrix(N, vector<int>(N, 0));
    vector<vector<int>> Stack(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Matrix[a - 1][b - 1] = Matrix[b - 1][a - 1] = c;
        Stack[a - 1].push_back(b - 1);
        Stack[b - 1].push_back(a - 1);
    }

    // print_matrix(Matrix);
    // print_stack(Stack);
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        int m = DFS(i, Matrix, Stack);
        if (m > max)
        {
            max = m;
        }
    }
    cout << max << endl;
}