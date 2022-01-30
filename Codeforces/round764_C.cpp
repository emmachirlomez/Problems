#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> frq(n + 1);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            while (a > n) {
                a /= 2;
            }
            frq[a]++;
        }
        bool ok = 1;
        for (int i = n; i > 0; i--) {
            ok &= (frq[i] > 0);
            if (frq[i] > 1)
                frq[i / 2] += frq[i] - 1, frq[i] = 1;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}