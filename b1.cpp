#include<bits/stdc++.h>
#define int long long
using namespace std;

int test, p;

main() {
    cin >> test;
    while(test--) {
        cin >> p;
        if(p == 1) {
            cout << 1 << endl;
            continue;
        }
        vector<int> vt;
        int res = 0;
        while(p > 1) {
            int kt = 0;
            for(int i = 9; i >= 2; i--) {
                if(p % i == 0) {
                    vt.push_back(i);
                    p /= i;
                    kt = 1;
                    break;
                }
            }
            if(kt == 0) {
                res = -1;
                break;
            }
        }
        if(res == -1) {
            cout << -1 << endl;
        } else {
            sort(vt.begin(), vt.end());
            for(int i = 0; i < vt.size(); i++) {
                cout << vt[i];
            }
            cout << endl;
        }
    }
}