#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int s;
        cin >> s;
        int n_0 = 0, n_1 = 0;
        for(int i = 0; i < s; i++) {
            char x;
            cin >> x;
            if (x == '1')
                n_1++;
            else
                n_0++;
        }
        if (s > 2)
            cout << "NO\n";
        else if (n_0 == 2 || n_1 == 2)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}