#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int mod = 1e9 + 7;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (int coin : nums)
        {
            if (i >= coin)
                dp[i] += dp[i - coin];
            if (dp[i] >= mod)
                dp[i] -= mod;
        }
    }

    cout << dp[x] << endl;

    return 0;
}