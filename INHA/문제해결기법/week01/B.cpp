
#include <iostream>
using namespace std;

int P[10'000'000] = {0};
#define MOD 1'000'000'007

int main()
{
    P[0] = 1, P[1] = 2;
    for (int i = 0; i < 10'000'000 - 2; i++)
        P[i + 2] = (P[i] + P[i + 1]) % MOD;

    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << P[N - 1] << endl;
    }
    return 0;
}