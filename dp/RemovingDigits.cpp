#include <bits/stdc++.h>
using namespace std;

int dp[1000005];
int dfs(int num)
{
    if (num == 0)
        return 0;

    if (dp[num] != -1)
        return dp[num];

    int ans = INT_MAX;
    int temp = num;
    while (temp)
    {
        int digit = temp % 10;
        temp /= 10;
        if (digit == 0)
            continue;

        ans = min(ans, 1 + dfs(num - digit));
    }

    return dp[num] = ans;
}
int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << dfs(n) << endl;
    return 0;
}
