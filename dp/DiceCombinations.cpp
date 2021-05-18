#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int mod = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int num = 1; num <= 6; num++)
        {
            if (i - num >= 0)
                dp[i] += dp[i - num];
            if (dp[i] >= mod)
                dp[i] -= mod;
        }
    }

    cout << dp[n] << endl;
    return 0;
}