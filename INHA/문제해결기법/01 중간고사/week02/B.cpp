#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<int> chicken_sizes(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> chicken_sizes[i];
        }

        // 누적 합 계산
        vector<int> sum_val(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            sum_val[i] = sum_val[i - 1] + chicken_sizes[i];
        }

        // dp[i][j]: i부터 j까지의 치킨집을 합친 비용의 최소값
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int gap = 2; gap <= n; gap++)
        { // 치킨집 간의 간격
            for (int i = 1; i <= n - gap + 1; i++)
            {
                int j = i + gap - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum_val[j] - sum_val[i - 1]);
                }
            }
        }

        cout << dp[1][n] << endl;
    }
    return 0;
}
