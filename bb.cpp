#include<bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

const int N = 1004;
int n, a[N], id[N];
vector<ii> le, ch;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 1) {
            le.push_back(ii(a[i], i));
        } else ch.push_back(ii(a[i], i));
    }
    sort(le.begin(), le.end());
    sort(ch.begin(), ch.end());
    int d1 = 0;
    int d2 = le.size() - 1;
    for(int i = 1; i <= n; i++) {
        if(a[i] % 2 == 1) {
            cout << le[d2].first << " ";
            d2--;
        } else {
            cout << ch[d1].first << " ";
            d1++;
        }
    }
}