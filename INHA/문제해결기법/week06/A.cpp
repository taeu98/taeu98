#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;    // 1<=T<=10
    int N;    // 2<=N<=100,000
    int M;    // 0<=M<N
    int A, B; // 1<=A,B<=N

    cin >> T; // 1. T 입력
    for (int i = 0; i < T; i++)
    {
        /* 변수 초기화 */
        int score = 0;
        vector<int> Int_A;
        vector<int> Int_B;

        cin >> N >> M; // 2. N, M 입력

        /* 변수 초기화 */
        vector<bool> bool_A(N, true); // 0<=A<=N-1
        vector<bool> bool_B(N, true); // 0<=B<=N-1

        /* 경기진행 (점수계산, 카드제거) */
        for (int j = 0; j < M; j++)
        {
            cin >> A >> B; // 3. A, B 입력
            bool_A[A - 1] = false;
            bool_B[B - 1] = false;
            (A >= B) ? score++ : score--;
        }

        /*  */
        for (int j = 0; j < N; j++)
        {
            if (bool_A[j] == true)
            {
                Int_A.push_back(j + 1);
            }
            if (bool_B[j] == true)
            {
                Int_B.push_back(j + 1);
            }
        }
        /****************************************/
        // cout << "\nTest Case : " << i + 1 << endl;
        // cout << "A : ";
        // for (int j : Int_A)
        // {
        //     cout << j << " ";
        // }
        // cout << endl;
        // cout << "B : ";
        // for (int j : Int_B)

        // {
        //     cout << j << " ";
        // }
        // cout << endl;
        // cout << "score : " << score << endl;
        /****************************************/

        while (Int_B.size() > 0)
        {
            if (Int_A[Int_A.size() - 1] >= Int_B[Int_B.size() - 1])
            {
                Int_A.pop_back();
                Int_B.pop_back();
                score++;
            }
            else
            {
                Int_B.pop_back();
            }
        }
        while (Int_A.size() > 0)
        {
            Int_A.pop_back();
            score--;
        }
        // cout << "score : " << score << endl;
        cout << ((score > 0) ? 1 : 0) << "\n";
    }
}