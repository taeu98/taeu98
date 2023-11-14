#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long C(string S)
{
    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'C')
        {
            sum += i - cnt++;
        }
    }
    return sum;
}
long long D(string S)
{
    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'D')
        {
            sum += i - cnt++;
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int N;
    string S;

    cin >> T;
    while (T--)
    {
        cin >> N >> S;
        cout << min(C(S), D(S)) << "\n";
    }
}