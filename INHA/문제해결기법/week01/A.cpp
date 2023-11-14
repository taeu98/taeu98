#include <iostream>
using namespace std;
int main()
{
    int T;       // 1<=T<=1,000
    string S, C; // 1<= |S,C| <= 5,000

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int count[26] = {0};
        cin >> S >> C;
        if (S.length() == C.length())
        {
            for (auto s : S)
                count[s - 'a'] += 1;
            for (auto c : C)
                count[c - 'a'] -= 1;
            bool flag = true;
            for (auto x : count)
                if (x != 0)
                    flag = false;
            cout << (flag ? "T" : "F") << endl;
        }
        else
            cout << 'F' << endl;
    }
}