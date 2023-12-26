#include<bits/stdc++.h>
using namespace std;

int numRollsToTarget(int n, int k, int target) {
    const int MOD = 1'000'000'007;
    // dp[i][j] = nr of ways to get sum j with i dices
    vector <vector <int>> dp(n + 1, vector <int> (target + 1));
    // dp[i][j] =  dp[i - 1][j - 1] (ultimul zar este 1)
    //           + dp[i - 1][j - 2] (ultimul zar este 2)
    //           + ...
    //           + dp[i - 1][j - k] (ultimul zar este k)
    // dp[0][0] = 1
    // dp[0][x] = 0
    
    // Init
    dp[0][0] = 1;
    
    // compute dp
    for (int i = 1; i <= n; i++) {
        // computing dp[i][???], knowing dp[< i][???]
        for (int j = 1; j <= target; j++) {
            int ans = 0;
            for (int l = 1; l <= min(k, j); l++)
                ans = (ans + dp[i - 1][j - l]) % MOD;
            dp[i][j] = ans;
        }
    }

    return dp[n][target];
}

int main() {
    int n = 2, k = 6, target = 7;
    cout << numRollsToTarget(n, k, target) << endl;
    return 0;
}