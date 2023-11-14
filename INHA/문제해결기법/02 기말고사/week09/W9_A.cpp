#include <iostream>
using namespace std;

#include <vector>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; // T : 1 ~ 100
    cin >> T;
    while (T--)
    {
        int N; // N : 4 ~ 1,000
        cin >> N;
        vector<vector<bool>> Friend(N, vector<bool>(N, false));
        vector<int> F(N, 0);
        for (int i = 0; i < N; i++)
        {
            int K;
            cin >> K;
            while (K--)
            {
                int X;
                cin >> X;
                if (!Friend[i][X - 1])
                {
                    Friend[X - 1][i] = true;
                    Friend[i][X - 1] = true;
                    F[X - 1]++;
                    F[i]++;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i < N; i++)
        {
            if (F[i] > F[0])
            {
                cnt++;
            }
        }
        cout << ((cnt > 2) ? "NO" : "YES") << "\n";
    }
}