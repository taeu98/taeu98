#include <iostream>
#include <map>
using namespace std;

int main()
{
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        map<int, string> N_S;
        map<string, int> S_N;
        string x;

        cin >> N;
        for (int j = 1; j <= N; j++)
        {
            cin >> x;
            N_S.insert({j, x});
            S_N.insert({x, j});
        }

        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> x;
            if (atoi(x.c_str()))
                cout << N_S[atoi(x.c_str())] << endl;
            else
                cout << S_N[x] << endl;
        }
    }
}