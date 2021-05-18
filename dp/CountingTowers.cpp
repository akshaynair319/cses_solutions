#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int n, m;

int dp[100001][101];
int dfs(int index, int prev, vector<int> &nums)
{
    //if all places have been filled
    if (index == nums.size())
        return 1;

    if (dp[index][prev] != -1)
        return dp[index][prev];

    if (index != 0 && nums[index] != 0 && abs(nums[index] - prev) > 1)
        return dp[index][prev] = 0;

    int ans = 0;
    //if its the first index
    if (index == 0)
    {
        if (nums[index] != 0)
        {
            ans = dfs(index + 1, nums[index], nums);
        }
        else
        {
            for (int i = 1; i <= m; i++)
            {
                nums[index] = i;
                ans += dfs(index + 1, nums[index], nums);
                if (ans >= mod)
                    ans -= mod;
                nums[index] = 0;
            }
        }
    }
    else
    {
        if (nums[index] != 0)
        {
            ans = dfs(index + 1, nums[index], nums);
        }
        else
        {
            nums[index] = nums[index - 1];
            ans += dfs(index + 1, nums[index], nums);
            if (ans >= mod)
                ans -= mod;
            nums[index] = 0;

            if (nums[index - 1] != 1)
            {
                nums[index] = nums[index - 1] - 1;
                ans += dfs(index + 1, nums[index], nums);
                if (ans >= mod)
                    ans -= mod;
                nums[index] = 0;
            }
            if (nums[index - 1] < m)
            {
                nums[index] = nums[index - 1] + 1;
                ans += dfs(index + 1, nums[index], nums);
                if (ans >= mod)
                    ans -= mod;
                nums[index] = 0;
            }
        }
    }

    return dp[index][prev] = ans;
}

int main()
{
    cin >> n >> m;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    memset(dp, -1, sizeof dp);
    cout << dfs(0, 0, nums) << endl;
    return 0;
}
