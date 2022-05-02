#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 34;
int n, f[N * 2][N][N];

int cal(int i, int d, int c) {
    if(i == 2 * n) {
        return 1;
    }
    if(f[i][d][c] != -1) return f[i][d][c];
    f[i][d][c] = 0;
    if(d < n) {
        f[i][d][c] += cal(i + 1, d + 1, c);
    }
    if(d > c) {
        f[i][d][c] += cal(i + 1, d, c + 1);
    }
    return f[i][d][c];
}

main() {
    int test;
    cin >> test;
    while(test--) {
        memset(f, 255, sizeof(f));
        cin >> n;
        cout << cal(0, 0, 0) << endl;
    }
}