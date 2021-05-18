#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mod = 1e9 + 7;
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int coin : nums)
    {
        for (int i = coin; i <= x; i++)
        {
            dp[i] += dp[i - coin];
            if (dp[i] >= mod)
                dp[i] -= mod;
        }
    }
    cout << dp[x] << endl;
    return 0;
}