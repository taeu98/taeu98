#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include <unordered_map>

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        unordered_map<string, int> mp;
        string S;
        for (int i = 0; i < N; i++)
        {
            cin >> S;
            mp.insert({S, i});
        }
        vector<int> V;
        for (int i = 0; i < N; i++)
        {
            cin >> S;
            V.push_back(mp[S]);
        }

        // for (auto i : V)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";

        int min_v = 0;
        int cnt = 0;
        vector<bool> visited(N, false);
        for (int i = 0; i < N; i++)
        {
            for (int j = min_v; j < N; j++)
            {
                if (!visited[j])
                {
                    min_v = j;
                    break;
                }
            }
            visited[V[i]] = true;
            if (min_v < V[i])
            {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}