#include<bits/stdc++.h>
using namespace std;

int a[100];

void ql(int i, int n) {
    if(i == n / 2) {
        for(int j = 1; j <= n; j++) {
            cout << a[j];
        }
        cout << " ";
        return;
    }
    a[i + 1] = 0;
    a[n - i] = 0;
    ql(i + 1, n);
    a[i + 1] = 1;
    a[n - i] = 1;
    ql(i + 1, n);
}

void solve(int n) {
    a[1] = 0;
    a[n] = 0;
    ql(1, n);
    a[1] = 1;
    a[n] = 1;
    ql(1, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        for(int i = 2; i <= n; i += 2) {
            solve(i);
        }
        cout << endl;
    }

    // solve(4);
}