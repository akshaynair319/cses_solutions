#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int coin : nums)
    {
        for (int i = coin; i <= x; i++)
        {
            if (dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
    return 0;
}