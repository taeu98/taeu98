#include <iostream>
#include <map>
using namespace std;
int level_1(int x, int s)
{
    double c = s / 2 + 0.5;
    return (x < c) ? x : s - x + 1;
}
int level_2(int x, int y, int s)
{
    return (level_1(x, s) < level_1(y, s)) ? level_1(x, s) : level_1(y, s);
}
int Func(int x1, int y1, int x2, int y2, int s)
{
    int G1 = level_2(x1, y1, s);
    int G2 = level_2(x2, y2, s);
    return (G1 > G2) ? G1 - G2 : G2 - G1;
}
int main()
{
    int T, N;
    int X1, X2;
    int Y1, Y2;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cin >> X1 >> Y1 >> X2 >> Y2;
        // cout << level_1(X1, N) << " " << level_1(Y1, N) << endl;
        // cout << level_1(X2, N) << " " << level_1(Y2, N) << endl;
        // cout << level_2(X1, Y1, N) << " " << level_2(X2, Y2, N) << endl;
        cout << Func(X1, Y1, X2, Y2, N) << endl;
    }
}