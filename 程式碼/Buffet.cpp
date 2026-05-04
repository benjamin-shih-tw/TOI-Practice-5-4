#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define fo(i,n) for(int i = 0 ; i < (n) ; i++)
#define foo(i,a,b) for(int i = (a) ; i <= (b) ; i++)
#define F first
#define S second
#define pb push_back
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, P, R;
    if (!(cin >> N >> P >> R)) return 0;

    vector<int> dp(P + 1, 0);

    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        
        vector<vector<int>> cur_dp(P + 1, vector<int>(R + 1, -1));
        
        for (int p = 0; p <= P; ++p) {
            cur_dp[p][0] = dp[p];
        }

        // 讀取當前類別的 M 種餐點
        for (int j = 0; j < M; ++j) {
            int c, d;
            cin >> c >> d;

            for (int p = P; p >= c; --p) {
                for (int r = R; r >= 1; --r) {
                    if (cur_dp[p - c][r - 1] != -1) {
                        cur_dp[p][r] = max(cur_dp[p][r], cur_dp[p - c][r - 1] + d);
                    }
                }
            }
        }

        for (int p = 0; p <= P; ++p) {
            for (int r = 0; r <= R; ++r) {
                if (cur_dp[p][r] != -1) {
                    dp[p] = max(dp[p], cur_dp[p][r]);
                }
            }
        }
    }

    int ans = 0;
    for (int p = 0; p <= P; ++p) {
        ans = max(ans, dp[p]);
    }
    
    cout << ans << "\n";

    return 0;
}