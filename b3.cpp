#include<bits/stdc++.h>

using namespace std;

const int N = 100004;
int n, k, a[N], test, f[N][21];

int gcd(int l, int r) {
    int x = log2(r - l + 1);
    return __gcd(f[l][x], f[r - (1 << x) + 1][x]);
}

void solve() {
    for(int i = 1; i <= n; i++) {
        f[i][0] = a[i];
    }
    for(int i = 1; (1 << i) <= n; i++) {
        for(int j = 1; j + (1 << i) - 1 <= n; j++) {
            f[j][i] = __gcd(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
        }
    }
}

bool check(int mid) {
    for(int i = 1; i + mid - 1 <= n; i++) {
        if(gcd(i, i + mid - 1) % k == 0) return true;
    }
    return false;
}

int main() {

    if(fopen("data.input", "r")) {
        freopen("data.input", "r", stdin);
    }

    cin >> test;
    while(test--) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        solve();
        int ans = n + 1;
        for(int i = 1; i <= n; i++) {
            int l = i, r = n;
            int res = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(gcd(i, mid) >= k) {
                    res = mid, l = mid + 1;
                }
                else r = mid - 1;
            }
            if(res != -1 && gcd(i, res) == k) {
                ans = min(ans, res - i + 1);
            }
        }
        if(ans == n + 1) cout << -1 << endl;
        else cout << ans << endl;
    }
}