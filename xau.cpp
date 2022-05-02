#include<bits/stdc++.h>
using namespace std;

int test;
string s;
int dem[30], dem2[30];

int main() {
    cin >> test;
    while(test--) {
        cin >> s;
        int sum = 0;
        for(int i = 0; i < s.length(); i++) {
            if(dem[s[i] - 'a' + 1] == 0) sum++;
            dem[s[i] - 'a' + 1] = 1;
        }
        // cout << sum << endl;
        int r = 0;
        int cur = 0;
        int res = s.length() + 1;
        for(int i = 0; i < s.length(); i++) {
            while(r < s.length()) {
                dem2[s[r] - 'a' + 1]++;
                if(dem2[s[r] - 'a' + 1] == 1) cur++;
                if(cur == sum) {res = min(res, r - i + 1); r++; break;}
                r++;
            }
            dem2[s[i] - 'a' + 1]--;
            // cout << s[i] << " " << dem2[s[i] - 'a' + 1] << " " << r << endl;
            if(dem2[s[i] - 'a' + 1] == 0) cur--;
        }
        cout << res << endl;
        memset(dem, 0, sizeof(dem));
        memset(dem2, 0, sizeof(dem2));
    }
}